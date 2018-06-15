import os
import shutil
import argparse
import sys
import subprocess

if __name__ == '__main__':
    script_dir = os.path.dirname(os.path.realpath(sys.argv[0]))

    parser = argparse.ArgumentParser(description="Generate CMake boilerplate project")

    placeholder = "plchldr"
    src = os.path.join(script_dir, placeholder)

    parser.add_argument("--name", required=True,
                        help="Project name")

    parser.add_argument("--dir", required=True, default=".",
                        help="Parent directory of the project (optional)")

    parser.add_argument("--force", help="If directory already exist, remove it (optional)",
                        action="store_true")

    args = parser.parse_args()

    project_name = args.name

    dst = os.path.join(args.dir, project_name)

    if args.force:
        shutil.rmtree(dst, ignore_errors=True)

    print(f"Creating project: {dst}")
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
                s = s.replace(placeholder, project_name)
                fd.write(s)

    print("Initializing git repository")
    subprocess.check_output(["git", "init"], cwd=dst)

    out = subprocess.check_output(
        "git config -f .gitmodules --get-regexp \'^submodule\\..*\\.path$\' || true",
        cwd=dst,
        stderr=subprocess.STDOUT,
        shell=True
    ).decode(sys.stdout.encoding)

    def rreplace(s, old, new, occurrence):
        li = s.rsplit(old, occurrence)
        return new.join(li)

    print("Restoring submodules:")
    for line in out.splitlines():
        submodule, path = line.split(" ")

        url_key=rreplace(submodule, ".path", ".url", 1)

        url = subprocess.check_output(
            f"git config -f .gitmodules --get {url_key} || true",
            cwd=dst,
            stderr=subprocess.STDOUT,
            shell=True
        ).decode(sys.stdout.encoding)

        url = url.strip()
        path = path.strip()

        print(url, path)

        url = subprocess.check_output(
            f"git submodule add {url} {path} || true",
            cwd=dst,
            stderr=subprocess.STDOUT,
            shell=True
        ).decode(sys.stdout.encoding)
