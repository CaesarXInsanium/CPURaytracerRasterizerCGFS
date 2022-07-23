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

UTILS_SRC = [
  'utils/ppm.c',
  'utils/canvas.c',
  'utils/scene.c',
  'utils/pixel.c'
]



utils = library(
  'utils',
  UTILS_SRC,
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
          link_with: utils
           )
