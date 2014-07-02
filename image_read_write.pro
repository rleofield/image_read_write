TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


#DESTDIR += bin
CONFIG  += x86_64


OBJECTS_DIR = .tmp
MOC_DIR = .tmp
UI_DIR = .tmp
RCC_DIR = .tmp


QMAKE_CXXFLAGS += -gdwarf-3


QMAKE_CXXFLAGS_DEBUG += -O0
QMAKE_CXXFLAGS_DEBUG += -std=c++0x
QMAKE_CXXFLAGS_DEBUG += -Wparentheses
QMAKE_CXXFLAGS_DEBUG += -Wreturn-type
QMAKE_CXXFLAGS_DEBUG += -Wshadow
QMAKE_CXXFLAGS_DEBUG += -Wextra
QMAKE_CXXFLAGS_DEBUG += -Wunused-parameter
QMAKE_CXXFLAGS_DEBUG -= -Wwrite-strings
QMAKE_CXXFLAGS_DEBUG -= -Wunused-variable
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-variable
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-but-set-variable

#QMAKE_CXXFLAGS_DEBUG += -Weffc++
QMAKE_CXXFLAGS_DEBUG -= -Wignored-qualifiers



QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_RELEASE += -std=c++0x
QMAKE_CXXFLAGS_RELEASE += -Wparentheses
QMAKE_CXXFLAGS_RELEASE += -Wreturn-type
QMAKE_CXXFLAGS_RELEASE += -Wshadow
QMAKE_CXXFLAGS_RELEASE += -Wextra
QMAKE_CXXFLAGS_RELEASE += -Wunused-parameter
QMAKE_CXXFLAGS_RELEASE -= -Wwrite-strings
QMAKE_CXXFLAGS_RELEASE -= -Wunused-variable
QMAKE_CXXFLAGS_RELEASE += -msse
QMAKE_CXXFLAGS_RELEASE += -Weffc++


message("qmake image_read_write")


SOURCES += \
    src/filefn/t_filename.cpp \
    src/hfile/filehelper.cpp \
    src/hstring/stringhelper.cpp \
    src/hstring/gettokens.cpp \
    src/hstring/t_2D_string.cpp \
    src/log/tLogImpl.cpp \
    src/log/tLog.cpp \
    src/img/rlf_streaks.cpp \
    src/img/rlf_math.cpp \
    src/img/rlf_blobs.cpp \
    src/img/rlf_blob.cpp \
    src/img/rlf_bin_filter.cpp \
    src/img/rimg_zoom.cpp \
    src/img/rimg_testimages.cpp \
    src/img/rimg_sobel.cpp \
    src/img/rimg_shift.cpp \
    src/img/rimg_rotate.cpp \
    src/img/rimg_rgb_names.cpp \
    src/img/rimg_median.cpp \
    src/img/rimg_math.cpp \
    src/img/rimg_lookuptable.cpp \
    src/img/rimg_graph.cpp \
    src/img/rimg_gauss.cpp \
    src/img/rimg_extend.cpp \
    src/img/rimg_binedit.cpp \
    src/img/rimg_bin_luts.cpp \
    src/img/rimg_aoi.cpp \
    src/img/rw/rimg_test_raw_rw.cpp \
    src/img/rw/rimg_rw_raw.cpp \
    src/img/rw/rimg_rw_png.cpp \
    src/img/rw/rimg_rw_jpeg.cpp \
    src/img/rw/rimg_rw_bmp.cpp \
    src/img/rw/rimg_rw_bin.cpp \
    src/img/rw/rimg_fs.cpp \
    src/img/rw/rimg_convert.cpp \
    src/img/rw/rimg_alloc_raw_data.cpp \
    src/main.cpp \
    src/htime/timer.cpp \
    src/img/rw/rimg_linear.cpp \
    src/img/rw/rimg_planar.cpp \
    src/img/rw/rimg_write.cpp \
    src/img/rw/rimg_read.cpp \
    src/img/rw/rimg_resolve_type.cpp \
    src/hfile/fn_control.cpp \
    src/filefn/filetreewalk.cpp \
    src/img/rw/rimg_tiff_r.cpp \
    src/img/rw/rimg_tiff_w.cpp \
    src/img/rw/rimg_tiff_r_decode.cpp

HEADERS += \
    src/filefn/t_filename.h \
    src/filefn/boost_cstdint.h \
    src/hfile/t_fncontrol.h \
    src/hfile/filehelper.h \
    src/hstring/stringhelper.h \
    src/hstring/gettokens.h \
    src/txtrw/rList.h \
    src/txtrw/wList.h \
    src/binrw/wBin.h \
    src/binrw/rBin.h \
    src/hstring/t_2D_string.h \
    src/log/tLogImpl.h \
    src/log/tLogEnum.h \
    src/log/tLogCategories.h \
    src/log/tLog.h \
    src/log/tLog_Category_default.h \
    src/log/tLog_Category_D.h \
    src/log/tLog_Category_C.h \
    src/log/tLog_Category_B.h \
    src/log/tLog_Category_A.h \
    src/log/tLfmCL.h \
    src/log/tLfm.h \
    src/helper.h \
    src/img/str_util.h \
    src/img/rlf_streak.h \
    src/img/rlf_math.h \
    src/img/rlf_blobs.h \
    src/img/rlf_blob.h \
    src/img/rlf_bin_filter.h \
    src/img/rimg_rgb_names.h \
    src/img/rimg_plane_linear.h \
    src/img/rimg_math.h \
    src/img/rimg_lookuptable.h \
    src/img/rimg_aoi.h \
    src/img/interface/rimg_rw_exceptions.h \
    src/img/interface/rimg_rgb_bgra_types.h \
    src/img/interface/rimg_read_write.h \
    src/img/interface/rimg_read_write_bin.h \
    src/img/interface/rimg_planar.h \
    src/img/interface/rimg_planar_typedefs.h \
    src/img/interface/rimg_linear.h \
    src/img/interface/rimg_imgsize_type.h \
    src/img/rw/rimg_test_raw_rw.h \
    src/img/rw/rimg_fs.h \
    src/img/rw/rimg_convert.h \
    src/img/rw/rimg_alloc_raw_data.h \
    src/minit/tObjPositionSize.h \
    src/minit/tLine.h \
    src/minit/tIndexID.h \
    src/minit/tArea.h \
    src/minit/t_3D_xyz.h \
    src/minit/t_2D_xy.h \
    src/minit/t_2D_Matrix.h \
    src/minit/boost_cstdint.h \
    src/htime/timer.h \
    src/img/rw/rimg_resolve_image_type.h \
    src/log/tLog_Category_rimg.h \
    src/hfile/fn_control.h \
    src/log/tLog_Category_with_cout.h \
    src/filefn/filetreewalk.h \
    src/filefn/filetreewalk_ref.h \
    src/log/tLog_Category_tiff.h \
    src/img/rw/rimg_tiff.h \
    src/img/rimg_t_read.h \
    src/img/rimg_t_write.h \
    src/log/tLfm.h \
    src/log/tLfmCL.h \
    src/log/tLog.h \
    src/log/tLogCategories.h \
    src/log/tLog_Category_A.h \
    src/log/tLog_Category_B.h \
    src/log/tLog_Category_C.h \
    src/log/tLog_Category_D.h \
    src/log/tLog_Category_default.h \
    src/log/tLog_Category_rimg.h \
    src/log/tLog_Category_tiff.h \
    src/log/tLogEnum.h \
    src/log/tLogImpl.h \
    src/filefn/filetreewalk.h


INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/log
INCLUDEPATH += $$PWD/src/minit
INCLUDEPATH += $$PWD/src/boost
INCLUDEPATH += $$PWD/src/ftw
INCLUDEPATH += $$PWD/src/filefn
INCLUDEPATH += $$PWD/src/hfile
INCLUDEPATH += $$PWD/src/htime
INCLUDEPATH += $$PWD/src/hide
INCLUDEPATH += $$PWD/src/hstring
INCLUDEPATH += $$PWD/src/txtrw
INCLUDEPATH += $$PWD/src/binrw
INCLUDEPATH += $$PWD/src/img/
INCLUDEPATH += $$PWD/src/img/interface
INCLUDEPATH += $$PWD/src/img/rw


INCLUDEPATH += $$PWD/../libpngjpegz/png/h $$PWD/../libpngjpegz/zlib/h $$PWD/../libpngjpegz/jpeg
DEPENDPATH += $$PWD/../libpngjpegz
PRE_TARGETDEPS += $$PWD/../libpngjpegz/libpngjpegz.a

LIBS += -L$$PWD/../libpngjpegz/ -lpngjpegz

LIBS += -lboost_system
LIBS += -lboost_filesystem

OTHER_FILES += \
    README.md \
    lgpl-3.0.txt


