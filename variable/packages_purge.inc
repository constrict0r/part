List of packages to purge using apt.

This list can be modified by passing a *packages_purge* array when including
the role on a playbook or via *--extra-vars* from a terminal.

This variable is empty by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{packages_purge: [gedit, rolldice]}"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       packages_purge:
         - gedit
         - rolldice

 # To a playbook from terminal.
 ansible-playbook -i tests/inventory tests/test-playbook.yml -K -e \
     "{packages_purge: [gedit, rolldice]}"