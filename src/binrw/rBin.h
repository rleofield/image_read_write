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


#ifndef T_BIN_READ_H
#define T_BIN_READ_H



/*! \file rList.h
*  \brief class t_bin_read, reads a binary file
*  \author Richard Albrecht
*/


#include <fstream>
#include <vector>
#include <stdexcept>
#include <cstdint>
#include <boost/filesystem.hpp>
#include <boost/cstdint.hpp>



namespace bin_read {

template <typename T>
inline char* to_char_ptr( std::vector<T>& b ) {
   return reinterpret_cast<char* >( b.data()  );
}
template <typename T>
inline char const* to_char_ptr( std::vector<T> const& b ) {
   return reinterpret_cast<char const* >( b.data()  );
}


   const std::string marker = "%s";

   namespace  {
      inline std::string FindAndReplace( const std::string& source,
                                         const std::string& find,
                                         const std::string& replace ) {
         size_t i;
         size_t start = 0;
         std::string ret = source;

         for( ; ( i = ret.find( find, start ) ) != std::string::npos; ) {
            ret.replace( i, find.length(), replace );
            start = i + replace.length();
         }

         return ret;
      }

      inline std::string replace( std::string const& msg, std::string const& s0 = "" ) {

         if( s0.size() > 0 ) {
            return FindAndReplace( msg, marker, s0 );
         }

         return msg;

      }

      inline bool file_exists_r( boost::filesystem::path const& p ) {
         if( !boost::filesystem::is_regular_file( p ) ) {
            return false;
         }

         boost::filesystem::file_status s = status( p );

         if( boost::filesystem::exists( s ) ) {
            return true;
         }

         return false;
      }

   }

   namespace err {

      const std::string msg_file_not_exists = "File doesn't exist: '" + marker + "'";
      const std::string msg_read_file = " Couldn't read file '" + marker + "'";

      inline std::string read_file( std::string const& s0 ) {
         return replace( msg_read_file, s0 );
      }
      inline std::string file_not_exists( std::string const& s0 ) {
         return replace( msg_file_not_exists, s0 );
      }
   }



   /*! bad_bin_read
       \param [in] msg  error message
       */
   class bad_bin_read: public std::runtime_error {
   public:
      bad_bin_read( const std::string& msg )
         : std::runtime_error( msg ) { }
   };

   /*! \class t_bin_read
       *  \brief reads a binary file
       *
       */
   class t_bin_read {

         std::string _filename = std::string();
         uint64_t _read_size = -1;

      public:

         //t_bin_read() = default;
         t_bin_read( const std::string& filename, uint64_t read_size = -1  ): _filename( filename ), _read_size(read_size) {}
         t_bin_read& operator= ( const t_bin_read& in ) = delete;
         t_bin_read( const t_bin_read& in ) = delete;
         ~t_bin_read() {}

         operator std::vector<uint8_t> () {
            std::vector<uint8_t> buf ;
            operator()(buf,_read_size);
            return std::move(buf);
         }

      private:

         void operator()( std::vector<uint8_t>& buf, uint64_t read_size = -1 )  {
            if( !file_exists_r( _filename ) ) {
               std::string s = err::file_not_exists( _filename );
               throw bad_bin_read( s );
            }


            auto mode = std::ios::in | std::ios::binary;
            std::ifstream fp( _filename.c_str(), mode );

            if( !fp.is_open() ) {
               auto s = err::read_file( _filename );
               throw bad_bin_read( s );
            }


            // very slow
            //std::istream_iterator<uint8_t> start(fp), end;
            //buf.assign(start, end);

            // fast
            uintmax_t size = boost::filesystem::file_size( _filename );

            if( read_size < size ) {
               size = read_size;
            }

            buf.resize( static_cast<size_t>( size ), 0 );
            auto buffer = to_char_ptr<uint8_t>( buf );
            fp.read( buffer, size );

            if( fp.eof() ) {
               auto s = err::read_file( _filename );
               throw bad_bin_read( s );
            }

         }

   };


} // end of ns bin_read

#endif

//EOF

