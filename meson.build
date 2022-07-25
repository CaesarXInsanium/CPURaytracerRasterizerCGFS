project(
  'ComputerGraphicsFromScratch',
  'c',
  version : '0.1',
  default_options: [
    'warning_level=3',
    'werror=true',
    'buildtype=debug',
    'debug=true',
    #'optimization=3',
    'c_std=c18'
  ])

DEPS = [
    dependency('cglm'),
    dependency('sdl2'),
]

lib_SRC = [
  'lib/ppm.c',
  'lib/canvas.c',
  'lib/scene.c',
  'lib/pixel.c',
  'lib/sphere.c'
]



#  cgfs = library(
#   'lib',
#   lib_SRC,
#   dependencies: DEPS,
# )


SRC = [
  'src/main.c'
  ]

executable(
          'software_raytrace',
          SRC, 
          install : true,
          dependencies: DEPS,
          # link_with:cgfs  
           )
