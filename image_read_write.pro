TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


# GCC schalter
#pragma GCC push_options
#pragma GCC diagnostic ignored "-Weffc++"
# func to protect
#pragma GCC pop_options
#DESTDIR += bin
CONFIG  += x86_64


OBJECTS_DIR = .tmp
MOC_DIR = .tmp
UI_DIR = .tmp
RCC_DIR = .tmp


QMAKE_CXXFLAGS += -gdwarf-3


QMAKE_CXXFLAGS_DEBUG += -O0
QMAKE_CXXFLAGS_DEBUG += -std=c++0x
QMAKE_CXXFLAGS_DEBUG += -Wall
QMAKE_CXXFLAGS_DEBUG += -Wcast-align
QMAKE_CXXFLAGS_DEBUG += -Wcast-qual
QMAKE_CXXFLAGS_DEBUG += -Wconversion

QMAKE_CXXFLAGS_DEBUG += -Weffc++
#QMAKE_CXXFLAGS_DEBUG += -Werror
QMAKE_CXXFLAGS_DEBUG += -Wextra
QMAKE_CXXFLAGS_DEBUG += -Wno-zero-as-null-pointer-constant
QMAKE_CXXFLAGS_DEBUG += -Wold-style-cast
QMAKE_CXXFLAGS_DEBUG += -Woverloaded-virtual
QMAKE_CXXFLAGS_DEBUG += -Wparentheses
QMAKE_CXXFLAGS_DEBUG += -Wpedantic
QMAKE_CXXFLAGS_DEBUG += -Wreturn-type
QMAKE_CXXFLAGS_DEBUG += -Wshadow
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-but-set-variable
QMAKE_CXXFLAGS_DEBUG += -Wunused-function
QMAKE_CXXFLAGS_DEBUG += -Wunused-parameter
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-result

QMAKE_CXXFLAGS_DEBUG += -Wno-unused-variable
QMAKE_CXXFLAGS_DEBUG += -Wwrite-strings



QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_RELEASE += -std=c++0x
QMAKE_CXXFLAGS_RELEASE += -Wparentheses
QMAKE_CXXFLAGS_RELEASE += -Wreturn-type
QMAKE_CXXFLAGS_RELEASE += -Wshadow
QMAKE_CXXFLAGS_RELEASE += -Wextra
QMAKE_CXXFLAGS_RELEASE += -Wno-unused-parameter
QMAKE_CXXFLAGS_RELEASE -= -Wwrite-strings
QMAKE_CXXFLAGS_RELEASE += -Wno-unused-variable
QMAKE_CXXFLAGS_RELEASE += -Wno-unused-but-set-variable
QMAKE_CXXFLAGS_RELEASE += -msse
QMAKE_CXXFLAGS_RELEASE += -Weffc++


message("qmake image_read_write")


SOURCES += \
    src/filefn/filetreewalk.cpp \
    src/filefn/t_filename.cpp \
    src/hfile/filehelper.cpp \
    src/hfile/fn_control.cpp \
    src/hstring/gettokens.cpp \
    src/hstring/stringhelper.cpp \
    src/hstring/t_2D_string.cpp \
    src/htime/timer.cpp \
    src/img/rimg_aoi.cpp \
    src/img/rimg_binedit.cpp \
    src/img/rimg_bin_luts.cpp \
    src/img/rimg_extend.cpp \
    src/img/rimg_gauss.cpp \
    src/img/rimg_graph.cpp \
    src/img/rimg_lookuptable.cpp \
    src/img/rimg_math.cpp \
    src/img/rimg_median.cpp \
    src/img/rimg_rgb_names.cpp \
    src/img/rimg_rotate.cpp \
    src/img/rimg_shift.cpp \
    src/img/rimg_sobel.cpp \
    src/img/rimg_testimages.cpp \
    src/img/rimg_zoom.cpp \
    src/img/rlf_bin_filter.cpp \
    src/img/rlf_blob.cpp \
    src/img/rlf_blobs.cpp \
    src/img/rlf_math.cpp \
    src/img/rlf_streaks.cpp \
    src/img/rw/rimg_alloc_raw_data.cpp \
    src/img/rw/rimg_convert.cpp \
    src/img/rw/rimg_fs.cpp \
    src/img/rw/rimg_linear.cpp \
    src/img/rw/rimg_planar.cpp \
    src/img/rw/rimg_read.cpp \
    src/img/rw/rimg_resolve_type.cpp \
    src/img/rw/rimg_rw_bin.cpp \
    src/img/rw/rimg_rw_bmp.cpp \
    src/img/rw/rimg_rw_jpeg.cpp \
    src/img/rw/rimg_rw_png.cpp \
    src/img/rw/rimg_rw_raw.cpp \
    src/img/rw/rimg_test_raw_rw.cpp \
    src/img/rw/rimg_tiff_r.cpp \
    src/img/rw/rimg_tiff_r_decode.cpp \
    src/img/rw/rimg_tiff_w.cpp \
    src/img/rw/rimg_write.cpp \
    src/log/tLog.cpp \
    src/log/tLogImpl.cpp \
    src/main.cpp




HEADERS += \
    src/binrw/rBin.h \
    src/binrw/wBin.h \
    src/filefn/filetreewalk.h \
    src/filefn/filetreewalk.h \
    src/filefn/filetreewalk_ref.h \
    src/filefn/t_filename.h \
    src/helper.h \
    src/hfile/filehelper.h \
    src/hfile/fn_control.h \
    src/hfile/t_fncontrol.h \
    src/hstring/gettokens.h \
    src/hstring/stringhelper.h \
    src/hstring/t_2D_string.h \
    src/htime/timer.h \
    src/img/interface/rimg_imgsize_type.h \
    src/img/interface/rimg_linear.h \
    src/img/interface/rimg_planar.h \
    src/img/interface/rimg_planar_typedefs.h \
    src/img/interface/rimg_read_write_bin.h \
    src/img/interface/rimg_read_write.h \
    src/img/interface/rimg_rgb_bgra_types.h \
    src/img/interface/rimg_rw_exceptions.h \
    src/img/rimg_aoi.h \
    src/img/rimg_lookuptable.h \
    src/img/rimg_math.h \
    src/img/rimg_plane_linear.h \
    src/img/rimg_rgb_names.h \
    src/img/rimg_t_read.h \
    src/img/rimg_t_write.h \
    src/img/rlf_bin_filter.h \
    src/img/rlf_blob.h \
    src/img/rlf_blobs.h \
    src/img/rlf_math.h \
    src/img/rlf_streak.h \
    src/img/rw/rimg_alloc_raw_data.h \
    src/img/rw/rimg_convert.h \
    src/img/rw/rimg_fs.h \
    src/img/rw/rimg_resolve_image_type.h \
    src/img/rw/rimg_test_raw_rw.h \
    src/img/rw/rimg_tiff.h \
    src/img/str_util.h \
    src/log/tLfmCL.h \
    src/log/tLfmCL.h \
    src/log/tLfm.h \
    src/log/tLfm.h \
    src/log/tLogCategories.h \
    src/log/tLogCategories.h \
    src/log/tLog_Category_A.h \
    src/log/tLog_Category_A.h \
    src/log/tLog_Category_B.h \
    src/log/tLog_Category_B.h \
    src/log/tLog_Category_C.h \
    src/log/tLog_Category_C.h \
    src/log/tLog_Category_default.h \
    src/log/tLog_Category_default.h \
    src/log/tLog_Category_D.h \
    src/log/tLog_Category_D.h \
    src/log/tLog_Category_rimg.h \
    src/log/tLog_Category_rimg.h \
    src/log/tLog_Category_tiff.h \
    src/log/tLog_Category_tiff.h \
    src/log/tLog_Category_with_cout.h \
    src/log/tLogEnum.h \
    src/log/tLogEnum.h \
    src/log/tLog.h \
    src/log/tLog.h \
    src/log/tLogImpl.h \
    src/log/tLogImpl.h \
    src/minit/t_2D_Matrix.h \
    src/minit/t_2D_xy.h \
    src/minit/t_3D_xyz.h \
    src/minit/tArea.h \
    src/minit/tIndexID.h \
    src/minit/tLine.h \
    src/minit/tObjPositionSize.h \
    src/txtrw/rList.h \
    src/txtrw/wList.h \
    src/log/tLog_Category_tiff.h




INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/log
INCLUDEPATH += $$PWD/src/minit
INCLUDEPATH += $$PWD/src/ftw
INCLUDEPATH += $$PWD/src/filefn
INCLUDEPATH += $$PWD/src/hfile
INCLUDEPATH += $$PWD/src/htime
INCLUDEPATH += $$PWD/src/hstring
INCLUDEPATH += $$PWD/src/txtrw
INCLUDEPATH += $$PWD/src/binrw
INCLUDEPATH += $$PWD/src/img/
INCLUDEPATH += $$PWD/src/img/interface
INCLUDEPATH += $$PWD/src/img/rw
INCLUDEPATH += $$PWD/src/test


INCLUDEPATH += $$PWD/../libpngjpegz/png/h $$PWD/../libpngjpegz/zlib/h $$PWD/../libpngjpegz/jpeg
DEPENDPATH += $$PWD/../libpngjpegz
PRE_TARGETDEPS += $$PWD/../libpngjpegz/libpngjpegz.a

LIBS += -L$$PWD/../libpngjpegz/ -lpngjpegz

LIBS += -lboost_system
LIBS += -lboost_filesystem

OTHER_FILES += \
    README.md \
    lgpl-3.0.txt


