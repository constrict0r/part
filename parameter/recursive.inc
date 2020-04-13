- *-r* (recursive): Enter recursively each directory on project's root
  directory and execute every |PROJECT|.sh script found, the current
  folder is also included.

 To avoid executing tests on a specific folder when running recursively,
 create a *.testignore* file on that folder, this is useful for example
 for running extensive bats tests on travis-ci and avoid error throwing
 for no logging in a long time.

 .. substitution-code-block:: bash

  ./|PROJECT|.sh -r