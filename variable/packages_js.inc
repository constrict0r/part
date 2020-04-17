List of packages to install via yarn.

This list can be modified by passing a *packages_js* array when including the
role on a playbook or via *--extra-vars* from a terminal.

If you want to install a specific package version, then specify *name* and
*version* attributes for the package.

This variable is empty by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{packages_js: [node-red, {name: requests, version: 2.22.0}]}"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       packages_js:
         - node-red
         - name: requests
           version: 2.22.0

 # To a playbook from terminal.
 ansible-playbook -i inventory my-playbook.yml -K -e \
     "{packages_js: [node-red, {name: requests, version: 2.22.0}]}"