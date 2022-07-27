#/bin/env bash

echo "Compiling Code..."
meson compile -C build
status=$?
if [ $status -eq 0 ]
then
  echo "Running..."
  ./build/software_raytrace
else
  echo "Build Error"
fi
