List of services to enable and start.

This list can be modified by passing a *services* array when including the
role on a playbook or via *--extra-vars* from a terminal.

This variable is empty by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{services: [mosquitto, nginx]}"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       services:
         - mosquitto
         - nginx

 # To a playbook from terminal.
 ansible-playbook -i tests/inventory tests/test-playbook.yml -K -e \
     "{services: [mosquitto, nginx]}"