import os
import shutil
import argparse
import sys

if __name__ == '__main__':
    script_dir = os.path.dirname(os.path.realpath(sys.argv[0]))

    parser = argparse.ArgumentParser()

    placeholder = "PLACEHOLDER"
    placeholder_cmake_version = "PLACEHOLDER_CMAKE_VERSION"
    src = os.path.join(script_dir, placeholder)

    parser.add_argument("--name", required=True,
                        help="Project name")

    parser.add_argument("--dir", required=True,
                        help="Project directory will be created here")

    parser.add_argument("--cmake_version",
                        help="CMake version in generated files",
                        default="2.8.12")

    args = parser.parse_args()

    project_name = args.name

    dst = os.path.join(args.dir, project_name)

    # if not os.path.isdir(dst):
    #     os.mkdir(dst)

    # shutil.rmtree(dst, ignore_errors=True)

    shutil.copytree(src, dst, symlinks=False, ignore=None)

    for root, dirs, files in os.walk(dst, topdown=False):
        for dirname in dirs:
            new_dirname = dirname.replace(placeholder, project_name)
            shutil.move(src=os.path.join(root, dirname),
                        dst=os.path.join(root, new_dirname))

        for filename in files:
            new_filename = filename.replace(placeholder, project_name)
            shutil.move(src=os.path.join(root, filename),
                        dst=os.path.join(root, new_filename))

    for root, _, files in os.walk(dst):
        for filename in files:
            filename = os.path.join(root, filename)
            with open(filename, "r") as fd:
                s = fd.read()

            with open(filename, 'w') as fd:
                s = s.replace(placeholder_cmake_version, args.cmake_version)
                s = s.replace(placeholder, project_name)
                fd.write(s)
