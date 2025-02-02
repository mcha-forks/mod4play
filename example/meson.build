example = get_option('example').disable_auto_if(meson.is_subproject())

if example.allowed()
  host_system = host_machine.system()

  sys_deps = []

  if host_system == 'darwin'
    sys_deps += [
      dependency(
        'appleframeworks',
        modules: ['quartzcore', 'cocoa', 'audiotoolbox', 'opengl'],
        required: example,
      ),
    ]
  elif host_system == 'android'
    sys_deps += dependency('glesv3', 'GLESv3', required: example)
    sys_deps += dependency('egl', 'EGL', required: example)
    sys_deps += dependency('log', required: example)
    sys_deps += dependency('android', required: example)
  elif host_system not in ['windows', 'cygwin', 'emscripten']
    sys_deps += dependency('x11', 'X11', required: example)
    sys_deps += dependency('xi', 'Xi', required: example)
    sys_deps += dependency('xcursor', 'Xcursor', required: example)
    sys_deps += dependency('gl', 'GL', required: example)
    sys_deps += dependency('alsa', 'asound', required: example)
    sys_deps += dependency('threads', required: example)
    sys_deps += dependency('dl', required: false)
    sys_deps += dependency('m', required: false)
  endif

  executable(
    'm4player',
    'm4player-sapp.c',
    dependencies: sys_deps + m4p_dep,
    win_subsystem: 'windows',
  )
endif
