project(
  'ComputerGraphicsFromScratch',
  'c',
  version : '0.1',
  default_options: [
    'warning_level=3',
    'werror=true',
    'buildtype=debugoptimized',
    'debug=true',
    #'optimization=3',
    'c_std=c18'
  ])

DEPS = [
    dependency('cglm'),
]

lib_SRC = [
  'lib/ppm.c',
  'lib/canvas.c',
  'lib/scene.c',
  'lib/pixel.c'
]



lib = library(
  'lib',
  lib_SRC,
  dependencies: DEPS,
)


SRC = [
  'src/main.c'
  ]

executable(
          'ppmraytracer',
          SRC, 
          install : true,
          dependencies: DEPS,
          link_with: lib
           )
