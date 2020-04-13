Absolute file path or URL to a *.yml* file that contains all or some of the
variables supported by this role.

It is recommended to use a *.yml* or *.yaml* extension for the
**configuration** file.

This variable is empty by default.

.. substitution-code-block:: bash

 # Using file path.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "configuration=/home/username/my-config.yml"

 # Using URL.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "configuration=https://my-url/my-config.yml"

To see how to write  a configuration file see the *YAML* file format section.