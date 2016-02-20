# Edit definitions below to specify paths to include files and libraries of all 3rd party libraries

#
# Edit these lines to set defaults for use of external libraries
#
set(USE_GFLAGS_DEFAULT 0)        # GFLAGS is disabled by default, enable with -DGFLAGS=1 cmake command line agrument
set(USE_SNAPPY_DEFAULT 0)        # SNAPPY is disabled by default, enable with -DSNAPPY=1 cmake command line agrument
set(USE_LZ4_DEFAULT 0)           # LZ4 is disabled by default, enable with -DLZ4=1 cmake command line agrument
set(USE_ZLIB_DEFAULT 0)          # ZLIB is disabled by default, enable with -DZLIB=1 cmake command line agrument
set(USE_BZIP2_DEFAULT 0)          # BZIP2 is disabled by default, enable with -DBZIP2=1 cmake command line agrument
set(USE_JEMALLOC_DEFAULT 0)      # JEMALLOC is disabled by default, enable with -DJEMALLOC=1 cmake command line agrument

#
# This example assumes all the libraries locate in directories under THIRDPARTY_HOME environment variable
# Set environment variable THIRDPARTY_HOME to point to your third party libraries home (Unix style dir separators)
# or change the paths below to reflect where the libraries actually reside
#
set (THIRDPARTY_LIBS "")         # Initialization, don't touch

#
# Edit these 4 lines to define paths to GFLAGS
#
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(GFLAGS_HOME $ENV{THIRDPARTY_HOME}/Gflags.Library)
    set(GFLAGS_INCLUDE ${GFLAGS_HOME}/inc/include)
    set(GFLAGS_LIB_DEBUG ${GFLAGS_HOME}/bin/debug/amd64/gflags.lib)
    set(GFLAGS_LIB_RELEASE ${GFLAGS_HOME}/bin/retail/amd64/gflags.lib)
else()
    set(GFLAGS_LIB_DEBUG -lgflags)
    set(GFLAGS_LIB_RELEASE -lgflags)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

# ================================================== GFLAGS ==================================================
#
# Don't touch these lines
#
if (DEFINED GFLAGS)
  set(USE_GFLAGS ${GFLAGS})
else ()
  set(USE_GFLAGS ${USE_GFLAGS_DEFAULT})
endif ()

if (${USE_GFLAGS} EQUAL 1)
  message(STATUS "GFLAGS library is enabled")
  
  if(DEFINED ENV{GFLAGS_INCLUDE})
    set(GFLAGS_INCLUDE $ENV{GFLAGS_INCLUDE})
  endif()
  
  if(DEFINED ENV{GFLAGS_LIB_DEBUG})
    set(GFLAGS_LIB_DEBUG $ENV{GFLAGS_LIB_DEBUG})
  endif()

  if(DEFINED ENV{GFLAGS_LIB_RELEASE})
    set(GFLAGS_LIB_RELEASE $ENV{GFLAGS_LIB_RELEASE})
  endif()
  
  set(GFLAGS_CXX_FLAGS -DGFLAGS=gflags)
  set(GFLAGS_LIBS debug ${GFLAGS_LIB_DEBUG} optimized ${GFLAGS_LIB_RELEASE})

  add_definitions(${GFLAGS_CXX_FLAGS})
  include_directories(${GFLAGS_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${GFLAGS_LIBS})
else ()
  message(STATUS "GFLAGS library is disabled")
endif ()

# ================================================== SNAPPY ==================================================
#
# Edit these 4 lines to define paths to Snappy
#
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(SNAPPY_HOME $ENV{THIRDPARTY_HOME}/Snappy.Library)
    set(SNAPPY_INCLUDE ${SNAPPY_HOME}/inc/inc)
    set(SNAPPY_LIB_DEBUG ${SNAPPY_HOME}/bin/debug/amd64/snappy.lib)
    set(SNAPPY_LIB_RELEASE ${SNAPPY_HOME}/bin/retail/amd64/snappy.lib)
else()
    set(SNAPPY_LIB_DEBUG -lsnappy)
    set(SNAPPY_LIB_RELEASE -lsnappy)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

#
# Don't touch these lines
#
if (DEFINED SNAPPY)
  set(USE_SNAPPY ${SNAPPY})
else ()
  set(USE_SNAPPY ${USE_SNAPPY_DEFAULT})
endif ()

if (${USE_SNAPPY} EQUAL 1)
  message(STATUS "SNAPPY library is enabled")
  
  if(DEFINED ENV{SNAPPY_INCLUDE})
    set(SNAPPY_INCLUDE $ENV{SNAPPY_INCLUDE})
  endif()
  
  if(DEFINED ENV{SNAPPY_LIB_DEBUG})
    set(SNAPPY_LIB_DEBUG $ENV{SNAPPY_LIB_DEBUG})
  endif()

  if(DEFINED ENV{SNAPPY_LIB_RELEASE})
    set(SNAPPY_LIB_RELEASE $ENV{SNAPPY_LIB_RELEASE})
  endif()
  
  set(SNAPPY_CXX_FLAGS -DSNAPPY)
  set(SNAPPY_LIBS debug ${SNAPPY_LIB_DEBUG} optimized ${SNAPPY_LIB_RELEASE})

  add_definitions(${SNAPPY_CXX_FLAGS})
  include_directories(${SNAPPY_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${SNAPPY_LIBS})
else ()
  message(STATUS "SNAPPY library is disabled")
endif ()

# ================================================== LZ4 ==================================================
#
# Edit these 4 lines to define paths to LZ4
#
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(LZ4_HOME $ENV{THIRDPARTY_HOME}/LZ4.Library)
    set(LZ4_INCLUDE ${LZ4_HOME}/inc/include)
    set(LZ4_LIB_DEBUG ${LZ4_HOME}/bin/debug/amd64/lz4.lib)
    set(LZ4_LIB_RELEASE ${LZ4_HOME}/bin/retail/amd64/lz4.lib)
else()
    set(LZ4_LIB_DEBUG -llz4)
    set(LZ4_LIB_RELEASE -llz4)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

#
# Don't touch these lines
#
if (DEFINED LZ4)
  set(USE_LZ4 ${LZ4})
else ()
  set(USE_LZ4 ${USE_LZ4_DEFAULT})
endif ()

if (${USE_LZ4} EQUAL 1)
  message(STATUS "LZ4 library is enabled")
  
  if(DEFINED ENV{LZ4_INCLUDE})
    set(LZ4_INCLUDE $ENV{LZ4_INCLUDE})
  endif()
  
  if(DEFINED ENV{LZ4_LIB_DEBUG})
    set(LZ4_LIB_DEBUG $ENV{LZ4_LIB_DEBUG})
  endif()

  if(DEFINED ENV{LZ4_LIB_RELEASE})
    set(LZ4_LIB_RELEASE $ENV{LZ4_LIB_RELEASE})
  endif()
  
  set(LZ4_CXX_FLAGS -DLZ4)
  set(LZ4_LIBS debug ${LZ4_LIB_DEBUG} optimized ${LZ4_LIB_RELEASE})

  add_definitions(${LZ4_CXX_FLAGS})
  include_directories(${LZ4_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${LZ4_LIBS})
else ()
  message(STATUS "LZ4 library is disabled")
endif ()

# ================================================== BZIP2 ==================================================
#
# Edit these 4 lines to define paths to BZIP2
#
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(BZIP2_HOME $ENV{THIRDPARTY_HOME}/BZIP2.Library)
    set(BZIP2_INCLUDE ${BZIP2_HOME}/inc/include)
    set(BZIP2_LIB_DEBUG ${BZIP2_HOME}/bin/debug/amd64/libbz2.lib)
    set(BZIP2_LIB_RELEASE ${BZIP2_HOME}/bin/retail/amd64/libbz2.lib)
else()
    set(BZIP2_LIB_DEBUG -lbz2)
    set(BZIP2_LIB_RELEASE -lbz2)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

#
# Don't touch these lines
#
if (DEFINED BZIP2)
  set(USE_BZIP2 ${BZIP2})
else ()
  set(USE_BZIP2 ${USE_BZIP2_DEFAULT})
endif ()

if (${USE_BZIP2} EQUAL 1)
  message(STATUS "BZIP2 library is enabled")
  
  if(DEFINED ENV{BZIP2_INCLUDE})
    set(BZIP2_INCLUDE $ENV{BZIP2_INCLUDE})
  endif()
  
  if(DEFINED ENV{BZIP2_LIB_DEBUG})
    set(BZIP2_LIB_DEBUG $ENV{BZIP2_LIB_DEBUG})
  endif()

  if(DEFINED ENV{BZIP2_LIB_RELEASE})
    set(BZIP2_LIB_RELEASE $ENV{BZIP2_LIB_RELEASE})
  endif()
  
  set(BZIP2_CXX_FLAGS -DBZIP2)
  set(BZIP2_LIBS debug ${BZIP2_LIB_DEBUG} optimized ${BZIP2_LIB_RELEASE})

  add_definitions(${BZIP2_CXX_FLAGS})
  include_directories(${BZIP2_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${BZIP2_LIBS})
else ()
  message(STATUS "BZIP2 library is disabled")
endif ()

# ================================================== ZLIB ==================================================
#
# Edit these 4 lines to define paths to ZLIB
#
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(ZLIB_HOME $ENV{THIRDPARTY_HOME}/ZLIB.Library)
    set(ZLIB_INCLUDE ${ZLIB_HOME}/inc/include)
    set(ZLIB_LIB_DEBUG ${ZLIB_HOME}/bin/debug/amd64/zlib.lib)
    set(ZLIB_LIB_RELEASE ${ZLIB_HOME}/bin/retail/amd64/zlib.lib)
else()
    set(ZLIB_LIB_DEBUG -lz)
    set(ZLIB_LIB_RELEASE -lz)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

#
# Don't touch these lines
#
if (DEFINED ZLIB)
  set(USE_ZLIB ${ZLIB})
else ()
  set(USE_ZLIB ${USE_ZLIB_DEFAULT})
endif ()

if (${USE_ZLIB} EQUAL 1)
  message(STATUS "ZLIB library is enabled")

  if(DEFINED ENV{ZLIB_INCLUDE})
    set(ZLIB_INCLUDE $ENV{ZLIB_INCLUDE})
  endif()
  
  if(DEFINED ENV{ZLIB_LIB_DEBUG})
    set(ZLIB_LIB_DEBUG $ENV{ZLIB_LIB_DEBUG})
  endif()

  if(DEFINED ENV{ZLIB_LIB_RELEASE})
    set(ZLIB_LIB_RELEASE $ENV{ZLIB_LIB_RELEASE})
  endif()
  
  set(ZLIB_CXX_FLAGS -DZLIB)
  set(ZLIB_LIBS debug ${ZLIB_LIB_DEBUG} optimized ${ZLIB_LIB_RELEASE})

  add_definitions(${ZLIB_CXX_FLAGS})
  include_directories(${ZLIB_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${ZLIB_LIBS})
else ()
  message(STATUS "ZLIB library is disabled")
endif ()

#
# Edit these 4 lines to define paths to Jemalloc
#
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(JEMALLOC_HOME $ENV{THIRDPARTY_HOME}/Jemalloc.Library)
    set(JEMALLOC_INCLUDE ${JEMALLOC_HOME}/inc/include)
    set(JEMALLOC_LIB_DEBUG ${JEMALLOC_HOME}/bin/debug/amd64/jemalloc.lib)
    set(JEMALLOC_LIB_RELEASE ${JEMALLOC_HOME}/bin/retail/amd64/jemalloc.lib)
else()
    set(JEMALLOC_LIB_DEBUG -ljemalloc)
    set(JEMALLOC_LIB_RELEASE -ljemalloc)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

# ================================================== JEMALLOC ==================================================
#
# Don't touch these lines
#
if (DEFINED JEMALLOC)
  set(USE_JEMALLOC ${JEMALLOC})
else ()
  set(USE_JEMALLOC ${USE_JEMALLOC_DEFAULT})
endif ()

if (${USE_JEMALLOC} EQUAL 1)
  message(STATUS "JEMALLOC library is enabled")
  set(JEMALLOC_CXX_FLAGS -DJEMALLOC)
  
  if(DEFINED ENV{JEMALLOC_INCLUDE})
    set(JEMALLOC_INCLUDE $ENV{JEMALLOC_INCLUDE})
  endif()
  
  if(DEFINED ENV{JEMALLOC_LIB_DEBUG})
    set(JEMALLOC_LIB_DEBUG $ENV{JEMALLOC_LIB_DEBUG})
  endif()

  if(DEFINED ENV{JEMALLOC_LIB_RELEASE})
    set(JEMALLOC_LIB_RELEASE $ENV{JEMALLOC_LIB_RELEASE})
  endif()

  set(JEMALLOC_LIBS debug ${JEMALLOC_LIB_DEBUG} optimized ${JEMALLOC_LIB_RELEASE})

  add_definitions(${JEMALLOC_CXX_FLAGS})
  include_directories(${JEMALLOC_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${JEMALLOC_LIBS})
  set (ARTIFACT_SUFFIX "_je")
else ()
  set (ARTIFACT_SUFFIX "")
  message(STATUS "JEMALLOC library is disabled")
endif ()
