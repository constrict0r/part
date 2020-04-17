List of packages to install via pip.

This list can be modified by passing a *packages_pip* array when including the
role on a playbook or via *--extra-vars* from a terminal.

If you want to install a specific package version, append the version to the
package name.

This variable is empty by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{packages_pip: ['bottle==0.12.17', 'whisper']}"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       packages_pip:
         - bottle==0.12.17
         - whisper

 # To a playbook from terminal.
 ansible-playbook -i inventory my-playbook.yml -K -e \
     "{packages_pip: ['bottle==0.12.17', 'whisper']}"