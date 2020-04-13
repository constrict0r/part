URL or list of URLs pointing to git skeleton repositories containing layouts
of directories and configuration files.

Each URL on system_skeleton will be checked to see if it points to a valid git
repository, and if it does, the git repository is cloned.

The contents of each cloned repository will then be copied to each user home
directory.

This variable is empty by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{user_skeleton: [https://gitlab.com/constrict0r/home]}"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       user_skeleton:
         - https://gitlab.com/constrict0r/home

 # To a playbook from terminal.
 ansible-playbook -i tests/inventory tests/test-playbook.yml -K -e \
     "{user_skeleton: [https://gitlab.com/constrict0r/home]}"