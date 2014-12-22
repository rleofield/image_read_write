/* --------------------------------------------------------------------------
Copyright 2012 by Richard Albrecht
richard.albrecht@rleofield.de
www.rleofield.de

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
------------------------------------------------------------------------------
*/

/*! \file main.cpp
\brief blob analyse


*/


//
#include <iostream>
#include <map>

#include "rimg_linear.h"
#include "rimg_planar.h"
#include "rimg_read_write.h"
#include "rimg_math.h"
#include "rlf_blobs.h"
#include "str_util.h"
#include "stringhelper.h"
#include "tLog_Category_default.h"

#include "rimg_rgb_names.h"
#include "rList.h"
#include "wList.h"
#include "t_filename.h"
#include "timer.h"
#include "t_filename.h"
#include "rimg_read_write.h"

using namespace rlf;


using rlf::rimg_linear::tImgLinear;
using rlf::rimg_linear::tImgLinear;
using rlf::rimg_linear::tImgViewLinear;

using namespace rlf::rimg_math;
using namespace rlf::rimg_rw;
using rlf_htime::tTimer;
using rlf_filefn::t_filename;



namespace {


   void demo_rgb( ) {
      tTimer timer2;
      tImgLinear  img1;



      try {
         tTimer            timer3;
         read( "0b_gray.bmp", img1 );
         double s =              timer3.seconds();
         string secs = str::toString( s, 8, 6 );
         cout << secs << " sec" << endl;
         // ca. 10 MB Image
         // 0.157852 sec, debug, gcc, amd 4850e
         // 24 bit 0.034079 sec, release, oder 0.037152 sec
         //  8 bit 0.012018 sec
      } catch( runtime_error rte ) {
         string msg =       rte.what();
         string id = typeid( rte ).name();
         cout << "Ex: " + msg << endl;
      }




      rlf::rimg_raw::write_raw_data( "test.raw", tImgViewLinear( img1 ) );
      size_t w = img1.size().w();
      size_t h = img1.size().h();
      tImgLinear img_read_raw;
      rlf::rimg_raw::read_raw_data( "test.raw", w, h, img_read_raw );

      rlf::rimg_rw::write( "0b_save_from_raw.tiff", tImgViewLinear( img_read_raw ), true );


      rlf::rimg_rw::read( "0b.jpeg", img1 );
      rlf::rimg_rw::read( "0b_gray.tif", img1 );

      tTimer timer;

      bool override_ = true;
      rlf::rimg_rw::write( "0b_save.bmp", tImgViewLinear( img1 ), override_ );
      rlf::rimg_rw::write_png( "0b_save.png", tImgViewLinear( img1 ), override_ );

      rlf::rimg_rw::write_jpeg( "0b_save.jpeg", tImgViewLinear( img1 ), override_ );
      rlf::rimg_rw::write( "0b_save.tiff", tImgViewLinear( img1 ), override_ );

      double s = timer.seconds();
      string secs = str::toString( s, 6, 3 );
      cout << secs << " sec" << endl;
      double s2 = timer2.seconds();
      string secs2 = str::toString( s2, 6, 3 );
      cout << secs2 << " sec" << endl;

      tImgLinear tiff;
      rlf::rimg_rw::read( "0b.png", tiff );
      bool ovr = true;
      rlf::rimg_rw::write( "0b_save_from_png.tif", tImgViewLinear( tiff ), ovr );


   }
   //   void demo_hide_single() {
   //      tImgPlanar  img_source_vickers;
   //      tImgPlanar  img_nothing_vickers;

   //      string path = "C:\\Projekte\\Zwick\\Bilder\\Bilder_2012_Messlinien_speichern\\test\\";
   //      path = "/home/richard/Desktop/sn/win/Bilder/Bilder_2012_Messlinien_speichern/test/";
   //      string vickers_source_path = path + "vickers_source.png";
   //      string vickers_changed_path = path + "vickers_target.png";
   //      string vickers_nothing_path = path + "abc.png";

   //      cout << "source: " << vickers_source_path << endl;
   //      cout << "target: " << vickers_changed_path << endl;
   //      cout << "target: " << vickers_nothing_path << endl;

   //      //rlf_hide::tResult sp = rlf_hide::result;


   //      read( vickers_source_path, img_source_vickers );
   //      read( vickers_nothing_path, img_nothing_vickers );

   //      img_source_vickers.name = vickers_source_path;
   //      img_nothing_vickers.name = vickers_nothing_path;
   //      LOGT_INFO( "LoadSetpoints" );

   //      vector<uint8_t> v_nothing;
   //      // no setpoints
   //      rlf_hide::eHiddenData ret1 = rlf_hide::read_hidden_data( img_nothing_vickers, v_nothing );
   //      rlf_hide::tResult sp_nothing = rlf_hide::result;

   //      // has setpoints
   //      vector<uint8_t> v_source;
   //      rlf_hide::eHiddenData ret2 = rlf_hide::read_hidden_data( img_source_vickers, v_source );
   //      rlf_hide::tResult sp_source = rlf_hide::result;

   //      // {D1=299.79434204101562 X1=287.22665405273437 Y1=110.06495666503906 ...}
   //      // {D1=299.79434204101562 X1=287.22665405273437 Y1=110.06495666503906 ...}

   //      // save to image with no setpoints

   //      rlf_hide::eHiddenData ret_save = rlf_hide::write_hidden_info( img_nothing_vickers, v_source );
   //      // write to disk
   //      write( vickers_changed_path, img_nothing_vickers, true );

   //      ret1 = rlf_hide::read_hidden_data( img_nothing_vickers, v_source );
   //      rlf_hide::tResult sp_source2 = rlf_hide::result;


   //      //rlf_hide::HiddenData1_Return ret2 = rlf_hide::LoadSetpoints( source, hd );
   //      //rlf_hide::SVHdnResult sp1 = rlf_hide::SetpointsMM;
   //      // {D1=299.79434204101562 X1=287.22665405273437 Y1=110.06495666503906 ...}
   //      if( !( sp_source2 == sp_source ) ) {
   //         ret1 = ret2;
   //      }



   //   }
   //   void demo_hide() {

   //      tImgPlanar  source;
   //      tImgPlanar  ctrl;
   //      tImgPlanar  write;
   //      tImgPlanar  target;

   //      try {

   //         rlf_hide::checksummap.clear();

   //         rlf_txtrw::t_text_read reader;
   //         std::list<std::string>  hasdata;
   //         std::list<std::string>  lines;
   //         reader.operator()( "allimages.txt", lines );

   //         try {
   //for( auto s: lines ) {
   //               rlf_filefn::t_filename fn( s );
   //               string n = fn.base();

   //               s = rlf_hstring::remove_quotes( s, '\"' );

   //               if( rlf_hstring::first_char( s ) != '#' ) {
   //                  //                  LOGT_INFO( "Load: " + s );
   //                  //                  LOGT_INFO( s );
   //                  tTimer t;
   //                  read( s, source );
   //                  double d = t.millies();

   //                  if( !source.is_rgb() ) {
   //                     if( source.is_mono8() ) {
   //                        rlf::rimg_rw::write( "aatest.BMP", source, true );
   //                        read( "aatest.BMP", ctrl );
   //                        //read( "aatest.BMP", write );
   //                        ctrl.name = s;
   //                        LOGT_INFO( "LoadSetpoints: " + s );
   //                        cout << s << endl;
   //                        vector<uint8_t> hd;
   //                        rlf_hide::eHiddenData ret0 = rlf_hide::read_hidden_data( ctrl, hd );
   //                        rlf_hide::tResult  sp2 = rlf_hide::result;
   //                        //rlf_hide::tResult  & sp2change = rlf_hide::result;
   //                        //sp2change.vickers.X1_left = 2.0;
   //                        //rlf_hide::eHiddenData ret2 = rlf_hide::write_hidden_info(write,hd);
   //                        //rlf_hide::eHiddenData ret3 = rlf_hide::read_hidden_data( write, hd );
   //                        //rlf_hide::tResult sp3 = rlf_hide::result;
   //                        //rlf_hide::tResult sp = rlf_hide::result;

   //                        if( ret0 == rlf_hide::eHiddenData::OK ) {
   //                           hasdata.push_back( s );
   //                           rlf_txtrw::t_write_ascii writer;
   //                           writer.operator()( "hasdata_data.txt", hasdata, true );
   //                           writer.operator()( "all_Vickers_2011.txt", rlf_hide::all_Vickers_2011, true );
   //                           writer.operator()( "all_Vickers.txt", rlf_hide::all_Vickers, true );
   //                           writer.operator()( "all_Knoop.txt", rlf_hide::all_Knoop, true );
   //                           writer.operator()( "all_Brinell.txt", rlf_hide::all_Brinell, true );
   //                           writer.operator()( "all_Nix.txt", rlf_hide::all_Nix, true );
   //                           writer.operator()( "all_checksum_OK_Mode_wrong.txt", rlf_hide::all_checksum_OK_Mode_wrong, true );


   //                        } else {
   //                           rlf_txtrw::t_write_ascii writer;
   //                           writer.operator()( "all_Vickers_2011.txt", rlf_hide::all_Vickers_2011, true );
   //                           writer.operator()( "all_Vickers.txt", rlf_hide::all_Vickers, true );
   //                           writer.operator()( "all_Knoop.txt", rlf_hide::all_Knoop, true );
   //                           writer.operator()( "all_Brinell.txt", rlf_hide::all_Brinell, true );
   //                           writer.operator()( "all_Nix.txt", rlf_hide::all_Nix, true );
   //                           writer.operator()( "all_checksum_OK_Mode_wrong.txt", rlf_hide::all_checksum_OK_Mode_wrong, true );

   //                           LOGT_INFO( "No Data:       " + s );
   //                        }
   //                     }
   //                  } else {
   //                     LOGT_INFO( "is rgb:        " + s );
   //                  }
   //               }
   //            }
   //         } catch( exception& ex ) {
   //            string msg = ex.what();
   //            LOGT_INFO( "Error: " + msg );
   //            return;

   //         }

   //         rlf_txtrw::t_write_ascii writer;
   //         writer.operator()( "all_Vickers_2011.txt", rlf_hide::all_Vickers_2011, true );
   //         writer.operator()( "all_Vickers.txt", rlf_hide::all_Vickers, true );
   //         writer.operator()( "all_Knoop.txt", rlf_hide::all_Knoop, true );
   //         writer.operator()( "all_Brinell.txt", rlf_hide::all_Brinell, true );
   //         writer.operator()( "all_Nix.txt", rlf_hide::all_Nix, true );
   //         writer.operator()( "all_checksum_OK_Mode_wrong.txt", rlf_hide::all_checksum_OK_Mode_wrong, true );
   //         LOGT_INFO( "ready" );
   //         size_t msize = rlf_hide::checksummap.size();

   //for( auto c: rlf_hide::checksummap ) {
   //            std::pair<uint32_t, uint32_t> p = c;
   //            uint32_t v = p.second;
   //            string vs = rlf_hstring::to_hex_0x( v );
   //            //LOGT_INFO( "CS: " + vs );
   //         }
   //      } catch( runtime_error rte ) {
   //         string msg = rte.what();
   //         string id = typeid( rte ).name();
   //         cout << "Ex: " + msg << endl;
   //         exit( 0 );
   //      }


   //   }



   void do_demo_planar_rgb() {

      //tMask mask = tMask::rgb;
      rlf::rimg_math::rimginterface r;
      tImgPlanar  img;

      tImgPlanar  source;
      tImgPlanar  ctrl;
      tImgPlanar  target;

      try {

         tTimer timer;
         read( "0b.jpeg", source );
         write( "0b_pngtest.jpeg", source, true, jpeg_compression::JPEG_QUALITY_DEFAULT );



         LOGT_INFO( "ready" );

         vector<string> files = {
            "Salomon.tif",

            //             "0b.tif",
            //             "0b_gray.tif",
            //             "0b_pal.tif",
            //             "4.1.05.tiff",
            //             "4.2.03.tiff",
            //             "5.1.09.tiff",
            //             "136jk081.tif",
            //             "a16.tif",
            //             "a_image.tif",
            //             "DeltaE_8bit_gamma2.2.tif",
            //             "lena512color.tiff",
            //             "lena_std.tif",
            //             "numbers.512.tiff",
            //             "ruler.512.tiff",
            //            "testpat.1k.tiff",
            //            "testsobel.tif",
            //            "texmos1.p512.tiff",
            //            "texmos3.s512.tiff",
            //            "wash-ir.tiff",
            //            "wf.tif",
            //            "wf_out.tif",


            "12_16_bit.tif"

         };

         for( string im : files ) {
            string tmp = im;
            string d = "tst/";
            string da = "tst/a/";
            im = d + im;
            tTimer a;
            LOGT_INFO( im );
            cout << im << endl;
            t_filename fn( im );

            LOGT_INFO( "read : " + fn.fullname() );
            read( fn.fullname(), source );
            string sec = to_string( a.seconds() );
            LOGT_INFO( sec );
            cout << sec << endl;
            tTimer b;
            string o = da + "00a_" + tmp + ".tif";
            rlf::rimg_rw::write( o, source, true );
            cout << o << endl;
            sec = to_string( b.seconds() );
            LOGT_INFO( sec );
            cout <<  sec << endl;
            LOGT_INFO( "write: " + o );
            cout << endl;
         }


         double s = timer.seconds();
         read( "large.bmp", source );
         rlf::rimg_rw::write( "ab.BMP", source, true );
         string img1 = "ab.BMP";
         read( img1, ctrl );
         LOGT_INFO( "Load: " + img1 );


         source.realloc( uint32_xy( 5, 5 ), tMask::mono );

         vcolors v = tMonoColor( 5 );
         source.setColor( v );

         tPlaneLinear8 linear;
         rimg_math::ToExtendedLinearArea( source.mono8(), linear, 1 );

         rimg_rw::read( "a1.BMP", source );


         rlf::rimg_rw::write( "a.tif", source, true );

         //r.zoom( source, target, 2.5, 2.5 );
         //rimg_convert::convertRGB_Gray( img, gray );
         //write_bmp( "zoomed.bmp", target, true ) ;
         //exit( 0 );

         tImgPlanar abs = tImgPlanar::create( source.size(), tMask::mono );   // = tImgPlanar::Create_mono8( img.size() );
         tImgPlanar orient = tImgPlanar::create( source.size(), tMask::mono );

         tTimer            timer3;
         cout << "start sobel" << endl;
         r.Sobel( source, abs, orient );
         tImgPlanar  gray;
         //convertRGB_Gray( img, gray );
         //write( "bl_gray.bmp", gray, true ) ;

         //rlf::rimg_math::Gauss3( gray );
         //rlf::rimg_math::Gauss3( gray );
         //rlf::rimg_math::Gauss3( gray );

         //double s =              timer3.seconds();
         //string secs = str::toString( s, 8, 6 );
         //cout << secs << " sec" << endl;

         cout << "end sobel" << endl;
         rlf::rimg_rw::write( "bl_abs.bmp", abs, true ) ;

         if( orient.has_data() ) {
            rlf::rimg_rw::write( "bl_orient.bmp", orient, true ) ;
         }

         //exit( 0 );

         rimg_rw::read( "wf_gray.tif", img );
         tBlobs bl;
         bl.threshold() = 25;
         bl.extract( img );
         bl.background() = 25;
         bl.min_area() = 350;

         bl.calculateMidpnt();
         bl.calculateSize();
         bl.calculateIntegral();
         bl.calculateArea();

         writeParam( bl, "w5.log" );
         writeToImage( bl, img, 100, 250 );

         rlf::rimg_rw::write( "wf_neu.tif", img, true );

         cout << "ok: " << endl;

      } catch( runtime_error rte ) {
         string msg = rte.what();
         string id = typeid( rte ).name();
         LOGT_ERROR( "Ex: " + msg );
         cout << "Ex: " + msg << endl;
         exit( 0 );
      }



   }

}

int main() {


   //uint32_t a = 128;
   //uint8_t v[4] = {0,0,0,128};
   //a = 0x100 * 0x100 * 0x100 * 128;
   // == (bin) 10000000000000000000000000000000 bin


   uint64_t size_ = UINTMAX_MAX;
   uint64_t size_1 = -1;

   if( size_ < 100 ) {
      cout << endl;
   }

   if( size_1 < 100 ) {
      cout << endl;
   }


   rlf_tlog::logger().setLogfile( "hidden" );
   rlf_tlog::logger().setLogLevel( rlf_tlog::eLevel::LDEBUG );
   LOGT_INFO( "start" );
   LOGT_INFO( "===================================" );

   // test
   //int sizeof_size_t = sizeof( size_t );
   //int sizeof_int = sizeof( int );

   cout << "started" << endl;


   try {
      //demo_rgb();
      //demo_hide();
      //demo_hide_single();
      do_demo_planar_rgb();
   } catch( runtime_error rte ) {
      string msg = rte.what();
      string id = typeid( rte ).name();
      cout << "Ex: " + msg << endl;
      exit( 0 );
   } catch( exception ex ) {
      string msg = ex.what();
      string id = typeid( ex ).name();
      cout << msg << endl;
      exit( 0 );
   }


   return 0;
}

