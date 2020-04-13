List of groups to add all users into. Each non-empty username will be added
to the groups specified on this variable.

This list can be modified by passing an *groups* array when including the role
on a playbook or via *--extra-vars* from a terminal.

This variable is empty by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{group: [disk, sudo]}"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       group:
         - disk
         - sudo

 # To a playbook from terminal.
 ansible-playbook -i tests/inventory tests/test-playbook.yml -K -e \
     "{group: [disk, sudo]}"