import sqlite3

if __name__ == "__main__":
    con = sqlite3.connect("dummy-project.db")
    cur = con.cursor()

    project_name = 'dummy-proj'
    res = cur.execute(f"SELECT id FROM source_package WHERE name='{project_name}'")
    project_id, *_ = res.fetchone()

    output = ""
    output += f"PYBIND11_MODULE(dummy, m) {{"
    output += "\n"

    res = cur.execute(f"SELECT id, name, qualified_name, access FROM class_declaration WHERE parent_package_id={project_id}")
    for (class_id, class_name, class_qname, class_access) in res.fetchall():
        if class_access != 3:
            continue

        output += f"    py::class_<{class_qname}>(m, \"{class_name}\")\n"
        res2 = cur.execute(f"SELECT name, signature FROM method_declaration WHERE class_id={class_id}")

        # TODO: Handle non-default constructors
        if class_name == 'Price':
            output += f"        .def(py::init<int, int>())\n"
        else:
            output += f"        .def(py::init<>())\n"

        for (name, signature) in res2.fetchall():
            if class_name in name:
                # TODO: Constructors works a bit different on python
                continue

            if "operator" in name:
                # TODO: Verify how operators should be exported
                continue

            output += f"        .def(\"{name}\", &{class_name}::{name})\n"
        output += "    ;\n"
    output += "}"

    print(output)
