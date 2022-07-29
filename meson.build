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

cgfs_src = [
  'cgfs/ppm.c',
  'cgfs/canvas.c',
  'cgfs/scene.c',
  'cgfs/pixel.c',
  'cgfs/sphere.c',
]



cgfs = library(
   'cgfs',
   cgfs_src,
   dependencies: DEPS,
 )


SRC = [
  'src/main.c',
  'src/app.c',
  'src/event.c',
  'src/keys.c',
  ]

executable(
          'software_raytrace',
          SRC, 
          install : true,
          dependencies: DEPS,
          link_with: cgfs  ,
          include_directories: include_directories('include')
)
