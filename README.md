image_read_write
================

image_read_write, writes/reads jpeg,tif,png,bmp images, zlib,pnglib,jpeglib needed

uses zlib:
http://www.zlib.net/


uses pnglib:
http://www.libpng.org/pub/png/libpng.html


uses jpeglib:
http://www.ijg.org/

'libpngjpegz.pro' project file to build a static library with zlib, pnglib and jpeglib with QtCreator 

gray level test images added, bug in handling gray images resolved

some functions renamed for clarity, 

added a class for images with separate RGB buffers<br>
this is a port from an old class, used in scientific work, 

2013.04.07, new version, code review only

2013.04.24, added a fast blob analysis for a gray level image<br>
    see test in main.cpp, from line 115 in method 'do_demo_planar_rgb()'<br>
    a new image class is added, with planar RGB values 'class tImgPlanar'<br>
    reading and writing of images is adapted to this new class<br>
    
    
2013.06.03, read and write of images moved to repository librimgrw   

2013.06.10, added some graphic functions, and math funktions for images
 
 
 2013.06.25
           added many new functions:
           see rimg_math.h
           
         size_t max_x( tImgPlanar const& im );
         size_t min_x( tImgPlanar const& im );
         size_t max_y( tImgPlanar const& im );
         size_t min_y( tImgPlanar const& im );


         //testpattern
         void fill( tImgPlanar& img, uint32_t val ) ;
         void rampx( tImgPlanar& img, size_t start = 1, size_t end = 255 );
         void rampy( tImgPlanar& img, size_t start = 1, size_t end = 255 );
         void rampxy( tImgPlanar& img, size_t start = 1, size_t end = 255 );
         bool rectangle( tImgPlanar& img,  uint32_t val, uint32_xy pos, uint32_xy size ) ;

         // rimg_math, insert
         bool Insert( const tImgViewPlanar& from, tImgPlanar& to, int32_xy xy ) ;


         // ring_math, aoi
         bool ExtractAoi( tImgViewPlanar const& s, tImgPlanar& t, tAoi& aoi ) ;


         // helper
         void ExtendImage( const tImgViewPlanar& in, tImgPlanar& extended, size_t kernel ) ;
         void ToExtendedImage( const tImgViewPlanar& in, tImgPlanar& out, int border ) ;
         void FitToImgPlanar( tIntPlane32 const& hor , tImgPlanar& img, int32_xy minmax ) ;
         void ToExtendedImageArea( const tPlane8& in, tPlane8& out, int border ) ;
         void ToExtendedImageArea( const tImgViewPlanar& in,
                                   tImgPlanar& extended, size_t border ) ;

         // lowpass
         void Gauss3( tImgPlanar& img );
         void Gauss( tImgPlanar& img, int ker_size ) ;
         void Gauss1( tImgPlanar& img, int ker_size ) ;

         // edges
         void Sobel( tImgViewPlanar const& source, tImgPlanar& abs, tImgPlanar& orient ) ;

         // bin edit

         void Add( tImgPlanar& sum,   const tImgViewPlanar& summand,  int constant ) ;
         void Add( tImgPlanar& source, int const1 ) ;


         void Subtract( tImgPlanar& target, const tImgViewPlanar& second, int const1 = 0 ) ;
         void Subtract( tImgPlanar& target, int constant ) ;

         void Or( tImgPlanar& target,  const tImgViewPlanar& or_ ) ;
         void Xor( tImgPlanar& target, const tImgViewPlanar& xor_ ) ;

         void BitwiseAnd( tImgPlanar& target, const tImgViewPlanar& xor_ ) ;

         void Average( tImgPlanar& target, const tImgViewPlanar& source ) ;
         void LogicalAnd( tImgPlanar& target, const tImgViewPlanar& second ) ;
         void AndBitwiseNot( tImgPlanar& target, const tImgViewPlanar& second ) ;


         void SubtractShift( tImgPlanar& target, const tImgViewPlanar& sub, int c , int shift ) ;
         void Scale( tImgPlanar& source, int scale ) ;
         void Multiplicate( tImgPlanar& source,  int factor ) ;


         vminmax Maximum( tImgPlanar& source ) ;
         vminmax Minimum( tImgPlanar& source ) ;

         void Normalize( tImgPlanar& source, Dword norm ) ;

         void CompareBinWithGray( tImgViewPlanar const& gray, tImgPlanar& bin, uint32_t thre, uint32_t c ) ;
         void BinMaskGray( tImgViewPlanar const& gray, tImgPlanar& bin, uint32_t color ) ;
         void Invert( tImgPlanar& gray ) ;


         bool Closing( tImgPlanar& im, int strength, int color );
         bool Opening( tImgPlanar& im, int strength, int color );
         bool Dilate( tImgPlanar& im, int strength, int color );
         bool Erode( tImgPlanar& im, int strength, int color );
         void BinEdit( tImgPlanar& im, int strength, int color, int edit_case );

         bool Closing( tPlane8& im, int strength, int color );
         bool Opening( tPlane8& im, int strength, int color );
         bool Dilate( tPlane8& im, int strength, int color );
         bool Erode( tPlane8& im, int strength, int color );
         bool BinEdit( tPlane8& im, int strength, int color, int edit_case );


         // rimg_graph
         void DrawText( tImgPlanar& img, uint32_xy xy, const string& text, vcolors const& colors ) ;
         void Line( tImgPlanar& img,  int32_xy from, int32_xy to, vcolors const& colors ) ;
         void Circle( tImgPlanar& img, int32_xy xy, int r, vcolors const& colors ) ;
         void FilledCircle( tImgPlanar& img, int32_xy xy, int r, vcolors const& colors ) ;
         void VerticalLine( tImgPlanar& img,  int xpos, vcolors const& colors ) ;
         void HorizontalLine( tImgPlanar& img,  int xpos, vcolors const& colors ) ;
         void WedgeHorizontal( tImgPlanar& img,  int sy ) ;
         void WedgeVertical( tImgPlanar& img,  int sy ) ;

         void OrthogonalCross( tImgPlanar& img, tixy pos, int size, vcolors const& colors ) ;
         void DiagonalCross( tImgPlanar& img, tixy xy, int const& c ) ;

         void DrawPixelList( tImgPlanar& img, std::vector<int32_xy> v,  uint32_t val ) ;
         std::vector<uint32_t> GetLinePixels( tImgPlanar const& img, uint32_xy from, uint32_xy to ) ;
         int GetLinePixels( tImgPlanar const& img, uint32_xy from, uint32_xy to, std::vector<uint32_t> &v ) ;


         // in rimg_median.cpp
         void Median( tPlane8& im, uint32_t kernel ) ;
         void Median( tImgPlanar& source, uint32_t kernel );

         void Rank( tPlane8 const& im, tPlane8& min_img, tPlane8& max_img, int kernel ) ;
         void Rank( tImgViewPlanar const& source,  tImgPlanar& min_img,  tImgPlanar& max_img, uint32_t kernel ) ;

         void Binarize( tPlane8& source, uint8_t thre, uint8_t color ) ;
         void Binarize( tImgPlanar& source, uint8_t thre, uint8_t color ) ;

         // zoom
         void ZoomIn( tImgPlanar const& source, tImgPlanar& target, int scale ) ;
         void ZoomOut( tImgPlanar const& source, tImgPlanar& target, int scale ) ;
         void Zoom( tImgPlanar const& source, tImgPlanar& target, double scale );
         void ZoomToSize( tImgPlanar const& source, tImgPlanar& target,  Dword sizex, Dword sizey ) ;
         void zoom( tImgPlanar const& source, tImgPlanar &target, double xscale, double yscale );
         
    test in progress,
        ZoomIn works
        ZoomOut works
        Sobel works
        Binarize works
        all in rimg_graph are working
        Scale works
        Multiplicate works 
        Gauss3 works
        all in helper are working
        all in testimages are working
        ExtractAoi works
        all image read/write is working
        Blob analysis is working, see main.cpp
            tBlobs bl;
            bl.threshold() = 25;
            bl.extract( img );
            bl.background() = 25;
            bl.min_area() = 50;
            bl.calculateMidpnt();
            bl.calculateSize();
            bl.calculateIntegral();
            bl.calculateArea();


planned: boost Unit Tests, HTML Doku, Doxygen Comments, Demo Client with Qt


