

/*
	****************************************************************************************
	Filename   :    Graphics.c
	Description:    Graphics
			
	Generated by Musa ÇUFALCI 2019
	Copyright (c) Musa ÇUFALCI All rights reserved.
	*****************************************************************************************
*/


/*-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
A U T H O R I D E N T I T Y
-----------------------------------------------------------------------------
-------------------------------- --------------------------------------------
Musa  ÇUFALCI
-----------------------------------------------------------------------------
R E V I S I O N H I S T O R Y
-----------------------------------------------------------------------------
Date Author Modification Description
Type
---------- ------ ------------- ---------------------------------------------
2019 MK Added First creating after project editing
-----------------------------------------------------------------------------
*/



/*******************************************************************************
********************************************************************************
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* The template of this heading text can be found in the file 'head.ewt' in the
* directory 'Platforms' of your Embedded Wizard installation directory. If you
* wish to adapt this text, please copy the template file 'head.ewt' into your
* project directory and edit the copy only. Please avoid any modifications of
* the original template file!
*
* Version  : 9.20
* Profile  : STM32F746
* Platform : STM.STM32.RGB565
*
*******************************************************************************/



#include "ewlocale.h"
#include "_GraphicsCanvas.h"
#include "_GraphicsWarpMatrix.h"
#include "_ResourcesBitmap.h"
#include "Graphics.h"

/* Compressed strings for the language 'Default'. */
static const unsigned int _StringsDefault0[] =
{
  0x00000322, /* ratio 49.38 % */
  0xB8007D00, 0x80000452, 0x00C20021, 0xC4000370, 0x006F0042, 0x400869D0, 0x0032800E,
  0x034800E6, 0x8A45CF40, 0x8000F118, 0x46CD8003, 0x4E4E6300, 0xA2879934, 0x151389C2,
  0x91F344A6, 0x1533C50C, 0x40048E13, 0x8D4A6393, 0xC432310E, 0x462191C9, 0x02546287,
  0xA493A368, 0x06358346, 0x04E00416, 0x0A9CCDE2, 0x9944F649, 0xA243E411, 0x48028F0F,
  0xD32271CA, 0xAA252EAC, 0x26B3C995, 0x1D1189C5, 0x940ADC4E, 0x768642AB, 0x283D3E74,
  0xB69520D5, 0x05DE5362, 0x5D615790, 0x9A15758E, 0xA15188B4, 0x8B0E96CD, 0xF8A8E52A,
  0x368C47A4, 0x4A51DE1D, 0x8742A1D3, 0xDDA22D38, 0xD0EBD3FA, 0x92294693, 0xA7767B55,
  0x0D049341, 0x9169D15E, 0xADA510A4, 0x9000A249, 0x92446282, 0xE5AB4518, 0x43A19118,
  0x7F55869A, 0xA97BEA14, 0x299889D2, 0x51F3ACDA, 0x34EB55AE, 0x4AEE32C5, 0xC944E4DD,
  0x6CE73D38, 0x78231CAC, 0xDA399B8A, 0xE2DCDE0C, 0xB33893F1, 0xD3AEC4E7, 0x001A0038,
  0x01B00060, 0x92450720, 0x9184891C, 0xE4182E49, 0x4C006C5C, 0x1F495761, 0x739656DD,
  0x9BD6ED68, 0x247DBF43, 0xD95677DC, 0x48575C87, 0x8510F72D, 0x1D083DCE, 0x08919900,
  0xC1627500, 0x146016F5, 0x7751A76D, 0xD6957DC3, 0xF58D9F76, 0x9D9A79D1, 0x567CDEB4,
  0x4716D7B9, 0xE2B859F1, 0xA7E1F686, 0x39FE7F1F, 0x02002004, 0x81A05832, 0x00040606,
  0x00000000
};

/* Constant values used in this 'C' module only. */
static const XPoint _Const0000 = { 0, 0 };
static const XStringRes _Const0001 = { _StringsDefault0, 0x0003 };
static const XRect _Const0002 = {{ 0, 0 }, { 0, 0 }};
static const XStringRes _Const0003 = { _StringsDefault0, 0x0041 };
static const XStringRes _Const0004 = { _StringsDefault0, 0x0076 };
static const XStringRes _Const0005 = { _StringsDefault0, 0x00B9 };
static const XStringRes _Const0006 = { _StringsDefault0, 0x0125 };

/* Initializer for the class 'Graphics::Canvas' */
void GraphicsCanvas__Init( GraphicsCanvas _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ResourcesBitmap__Init( &_this->_Super, aLink, aArg );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( GraphicsCanvas );

  /* Call the user defined constructor */
  GraphicsCanvas_Init( _this, aArg );
}

/* Re-Initializer for the class 'Graphics::Canvas' */
void GraphicsCanvas__ReInit( GraphicsCanvas _this )
{
  /* At first re-initialize the super class ... */
  ResourcesBitmap__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Graphics::Canvas' */
void GraphicsCanvas__Done( GraphicsCanvas _this )
{
  /* Finalize this class */
  _this->_VMT = EW_CLASS( GraphicsCanvas );

  /* Call the user defined destructor of the class */
  GraphicsCanvas_Done( _this );

  /* Don't forget to deinitialize the super class ... */
  ResourcesBitmap__Done( &_this->_Super );
}

/* 'C' function for method : 'Graphics::Canvas.Done()' */
void GraphicsCanvas_Done( GraphicsCanvas _this )
{
  if ( _this->attached )
    GraphicsCanvas_DetachBitmap( _this );
}

/* 'C' function for method : 'Graphics::Canvas.Init()' */
void GraphicsCanvas_Init( GraphicsCanvas _this, XHandle aArg )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  _this->Super1.Mutable = 1;
}

/* 'C' function for method : 'Graphics::Canvas.OnSetFrameSize()' */
void GraphicsCanvas_OnSetFrameSize( GraphicsCanvas _this, XPoint value )
{
  XHandle handle;

  if (( value.X <= 0 ) || ( value.Y <= 0 ))
    value = _Const0000;

  if ( !EwCompPoint( value, _this->Super1.FrameSize ))
    return;

  if ( _this->attached )
  {
    EwThrow( EwLoadString( &_Const0001 ));
    return;
  }

  _this->Super1.FrameSize = value;
  _this->Super1.Animated = (XBool)(((( _this->Super1.FrameSize.X > 0 ) && ( _this->Super1.FrameSize.Y 
  > 0 )) && ( _this->Super1.FrameDelay > 0 )) && ( _this->Super1.NoOfFrames > 1 ));

  if ( _this->Super1.bitmap == 0 )
    return;

  handle = _this->Super1.bitmap;
  EwFreeBitmap((XBitmap*)handle );
  _this->Super1.bitmap = 0;
}

/* 'C' function for method : 'Graphics::Canvas.Update()' */
void GraphicsCanvas_Update( GraphicsCanvas _this )
{
  if ((( _this->Super1.bitmap == 0 ) && ( _this->Super1.FrameSize.X > 0 )) && ( 
      _this->Super1.FrameSize.Y > 0 ))
  {
    XPoint frameSize = _this->Super1.FrameSize;
    XInt32 noOfFrames = _this->Super1.NoOfFrames;
    XInt32 frameDelay = _this->Super1.FrameDelay;
    XHandle handle = 0;
    {
      handle = (XHandle)EwCreateBitmap( EW_PIXEL_FORMAT_NATIVE, frameSize, 
                                        frameDelay, noOfFrames );
    }
    _this->Super1.bitmap = handle;

    if ( _this->Super1.bitmap == 0 )
    {
      _this->Super1.FrameSize = _Const0000;
      _this->Super1.FrameDelay = 0;
      _this->Super1.NoOfFrames = 1;
    }

    _this->InvalidArea = EwNewRect2Point( _Const0000, _this->Super1.FrameSize );
  }

  if ( !EwIsRectEmpty( _this->InvalidArea ))
  {
    if (( _this->Super1.FrameSize.X > 0 ) && ( _this->Super1.FrameSize.Y > 0 ))
      EwSignal( _this->OnDraw, ((XObject)_this ));

    _this->InvalidArea = _Const0002;
  }
}

/* The method DetachBitmap() exists for the integration purpose with the underlying 
   target system. You will never need to invoke this method directly from your GUI 
   application. The method is invoked after the screen update is finished and the 
   canvas object should be detached from the framebuffer. */
GraphicsCanvas GraphicsCanvas_DetachBitmap( GraphicsCanvas _this )
{
  if ( !_this->attached )
  {
    EwThrow( EwLoadString( &_Const0003 ));
    return 0;
  }

  _this->Super1.bitmap = 0;
  _this->attached = 0;
  _this->Super1.FrameSize = _Const0000;
  _this->Super1.FrameDelay = 0;
  _this->Super1.NoOfFrames = 1;
  _this->Super1.Animated = 0;
  return _this;
}

/* Wrapper function for the non virtual method : 'Graphics::Canvas.DetachBitmap()' */
GraphicsCanvas GraphicsCanvas__DetachBitmap( void* _this )
{
  return GraphicsCanvas_DetachBitmap((GraphicsCanvas)_this );
}

/* The method AttachBitmap() exists for the integration purpose with the underlying 
   target system. You will never need to invoke this method directly from your GUI 
   application. The method is invoked at the beginning of the screen update.
   The method connects the canvas object with the framebuffer. */
GraphicsCanvas GraphicsCanvas_AttachBitmap( GraphicsCanvas _this, XHandle aBitmap )
{
  XInt32 noOfFrames;
  XPoint frameSize;
  XInt32 frameDelay;

  if ( _this->Super1.bitmap != 0 )
  {
    EwThrow( EwLoadString( &_Const0004 ));
    return 0;
  }

  if ( aBitmap == 0 )
    return _this;

  _this->Super1.bitmap = aBitmap;
  _this->attached = 1;
  noOfFrames = 1;
  frameSize = _Const0000;
  frameDelay = 0;
  {
    XBitmap* bmp = (XBitmap*)aBitmap;

    noOfFrames = bmp->NoOfFrames;
    frameSize  = bmp->FrameSize;
    frameDelay = bmp->FrameDelay;
  }
  _this->Super1.NoOfFrames = noOfFrames;
  _this->Super1.FrameSize = frameSize;
  _this->Super1.FrameDelay = frameDelay;
  _this->Super1.Animated = (XBool)(( _this->Super1.FrameDelay > 0 ) && ( _this->Super1.NoOfFrames 
  > 1 ));
  return _this;
}

/* Wrapper function for the non virtual method : 'Graphics::Canvas.AttachBitmap()' */
GraphicsCanvas GraphicsCanvas__AttachBitmap( void* _this, XHandle aBitmap )
{
  return GraphicsCanvas_AttachBitmap((GraphicsCanvas)_this, aBitmap );
}

/* The method WarpBitmap() performs the projection of a rectangular source bitmap 
   area onto a four corner polygon within the destination canvas. The bitmap is 
   specified in the parameter aBitmap and the desired area to copy in aSrcRect. 
   In case of a multi-frame bitmap the desired frame can be selected in the parameter 
   aFrameNr.
   The destination polygon is determined by the coordinates aX1,aY1 .. aX4,aY4. 
   The coefficients aW1 .. aW4 are responsible for the perspective distortion. The 
   parameters aColor1, aColor2, aColor3, aColor4 determine the colors or opacities 
   at the corresponding corners of the polygon area. The parameter aClip limits 
   the drawing operation. Pixel lying outside this area remain unchanged. The last 
   aBlend parameter controls the mode how drawn pixel are combined with the pixel 
   already existing in the destination bitmap. If aBlend is 'true', the drawn pixel 
   are alpha-blended with the background, otherwise the drawn pixel will overwrite 
   the old content. */
void GraphicsCanvas_WarpBitmap( GraphicsCanvas _this, XRect aClip, ResourcesBitmap 
  aBitmap, XInt32 aFrameNr, XFloat aDstX1, XFloat aDstY1, XFloat aDstW1, XFloat 
  aDstX2, XFloat aDstY2, XFloat aDstW2, XFloat aDstX3, XFloat aDstY3, XFloat aDstW3, 
  XFloat aDstX4, XFloat aDstY4, XFloat aDstW4, XRect aSrcRect, XColor aColor1, XColor 
  aColor2, XColor aColor3, XColor aColor4, XBool aBlend, XBool aFilter )
{
  XFloat x1;
  XFloat x2;
  XFloat y1;
  XFloat y2;
  XHandle dstBitmap;
  XHandle srcBitmap;
  XInt32 dstFrameNr;

  if ( _this->Super1.bitmap == 0 )
    ResourcesBitmap__Update( _this );

  if ( _this->Super1.bitmap == 0 )
    return;

  if (((( aBitmap == 0 ) || ( aBitmap->bitmap == 0 )) || ( aFrameNr < 0 )) || ( 
      aFrameNr >= aBitmap->NoOfFrames ))
    return;

  x1 = aDstX1;
  x2 = aDstX2;
  y1 = aDstY1;
  y2 = aDstY2;

  if ( aDstX2 < x1 )
    x1 = aDstX2;

  if ( aDstX3 < x1 )
    x1 = aDstX3;

  if ( aDstX4 < x1 )
    x1 = aDstX4;

  if ( aDstX2 > x2 )
    x2 = aDstX2;

  if ( aDstX3 > x2 )
    x2 = aDstX3;

  if ( aDstX4 > x2 )
    x2 = aDstX4;

  if ( aDstY2 < y1 )
    y1 = aDstY2;

  if ( aDstY3 < y1 )
    y1 = aDstY3;

  if ( aDstY4 < y1 )
    y1 = aDstY4;

  if ( aDstY2 > y2 )
    y2 = aDstY2;

  if ( aDstY3 > y2 )
    y2 = aDstY3;

  if ( aDstY4 > y2 )
    y2 = aDstY4;

  if ((((( x2 - x1 ) > 4096.000000f ) || (( x2 - x1 ) < -4096.000000f )) || (( y2 
      - y1 ) > 4096.000000f )) || (( y2 - y1 ) < -4096.000000f ))
  {
    EwTrace( "%s", EwLoadString( &_Const0005 ));
    return;
  }

  dstBitmap = _this->Super1.bitmap;
  srcBitmap = aBitmap->bitmap;
  dstFrameNr = _this->DstFrameNr;
  {
    EwWarpBitmap((XBitmap*)dstBitmap, (XBitmap*)srcBitmap, dstFrameNr, aFrameNr,
                  aClip, aDstX1, aDstY1, aDstW1, aDstX2, aDstY2, aDstW2, 
                  aDstX3, aDstY3, aDstW3, aDstX4, aDstY4, aDstW4, aSrcRect, aColor1,
                  aColor2, aColor3, aColor4, aBlend, aFilter );
  }
}

/* The method ScaleBitmap() copies and scales an area of a aBitmap into the canvas. 
   The bitmap is specified in the parameter aBitmap and the desired area to copy 
   in aSrcRect. In case of a multi-frame bitmap the desired frame can be selected 
   in the parameter aFrameNr.
   The destination area in canvas is determined by the parameter aDstRect. The parameters 
   aColorTL, aColorTR, aColorBL, aColorBR determine the colors or opacities at the 
   corresponding corners of the aDstRect area.
   The parameter aClip limits the drawing operation. Pixel lying outside this area 
   remain unchanged. The last aBlend parameter controls the mode how drawn pixel 
   are combined with the pixel already existing in the destination bitmap. If aBlend 
   is 'true', the drawn pixel are alpha-blended with the background, otherwise the 
   drawn pixel will overwrite the old content. */
void GraphicsCanvas_ScaleBitmap( GraphicsCanvas _this, XRect aClip, ResourcesBitmap 
  aBitmap, XInt32 aFrameNr, XRect aDstRect, XRect aSrcRect, XColor aColorTL, XColor 
  aColorTR, XColor aColorBR, XColor aColorBL, XBool aBlend, XBool aFilter )
{
  XFloat top;
  XFloat left;
  XFloat right;
  XFloat bottom;
  XHandle dstBitmap;
  XHandle srcBitmap;
  XInt32 dstFrameNo;

  if ( _this->Super1.bitmap == 0 )
    ResourcesBitmap__Update( _this );

  if ( _this->Super1.bitmap == 0 )
    return;

  if (((( aBitmap == 0 ) || ( aBitmap->bitmap == 0 )) || ( aFrameNr < 0 )) || ( 
      aFrameNr >= aBitmap->NoOfFrames ))
    return;

  top = (XFloat)aDstRect.Point1.Y;
  left = (XFloat)aDstRect.Point1.X;
  right = (XFloat)aDstRect.Point2.X;
  bottom = (XFloat)aDstRect.Point2.Y;

  if ((((( right - left ) > 4096.000000f ) || (( right - left ) < -4096.000000f )) 
      || (( bottom - top ) > 4096.000000f )) || (( bottom - top ) < -4096.000000f ))
  {
    EwTrace( "%s", EwLoadString( &_Const0006 ));
    return;
  }

  dstBitmap = _this->Super1.bitmap;
  srcBitmap = aBitmap->bitmap;
  dstFrameNo = _this->DstFrameNr;
  {
    EwWarpBitmap((XBitmap*)dstBitmap, (XBitmap*)srcBitmap, dstFrameNo, aFrameNr, aClip,
                  left,  top,    1.0f, right, top,    1.0f,
                  right, bottom, 1.0f, left,  bottom, 1.0f,
                  aSrcRect, aColorTL, aColorTR, aColorBR, aColorBL, aBlend, aFilter );
  }
}

/* The method CopyBitmap() copies an area of a aBitmap into the canvas. The bitmap 
   is specified in the parameter aBitmap. In case of a multi-frame bitmap the desired 
   frame can be selected in the parameter aFrameNr.
   The area to copy the bitmap is determined by the parameter aDstRect. The optional 
   aSrcPos parameter determines a displacement of the bitmap within this aDstRect 
   area. The parameters aColorTL, aColorTR, aColorBL, aColorBR determine the colors 
   or opacities at the corresponding corners of the aDstRect area.
   The parameter aClip limits the drawing operation. Pixel lying outside this area 
   remain unchanged. The last aBlend parameter controls the mode how drawn pixel 
   are combined with the pixel already existing in the destination bitmap. If aBlend 
   is 'true', the drawn pixel are alpha-blended with the background, otherwise the 
   drawn pixel will overwrite the old content. */
void GraphicsCanvas_CopyBitmap( GraphicsCanvas _this, XRect aClip, ResourcesBitmap 
  aBitmap, XInt32 aFrameNr, XRect aDstRect, XPoint aSrcPos, XColor aColorTL, XColor 
  aColorTR, XColor aColorBR, XColor aColorBL, XBool aBlend )
{
  XHandle dstBitmap;
  XHandle srcBitmap;
  XInt32 dstFrameNr;

  if ( _this->Super1.bitmap == 0 )
    ResourcesBitmap__Update( _this );

  if ( _this->Super1.bitmap == 0 )
    return;

  if (((( aBitmap == 0 ) || ( aBitmap->bitmap == 0 )) || ( aFrameNr < 0 )) || ( 
      aFrameNr >= aBitmap->NoOfFrames ))
    return;

  dstBitmap = _this->Super1.bitmap;
  srcBitmap = aBitmap->bitmap;
  dstFrameNr = _this->DstFrameNr;
  {
    EwCopyBitmap((XBitmap*)dstBitmap, (XBitmap*)srcBitmap, dstFrameNr, aFrameNr,
                  aClip, aDstRect, aSrcPos, aColorTL, aColorTR, aColorBR, aColorBL,
                  aBlend );
  }
}

/* The method FillRectangle() fills an area of canvas. The area is determined by 
   the parameter aDstRect. The parameters aColorTL, aColorTR, aColorBL, aColorBR 
   determine the colors at the corresponding corners of the aDstRect area.
   The parameter aClip limits the drawing operation. Pixel lying outside this area 
   remain unchanged. The last aBlend parameter controls the mode how drawn pixel 
   are combined with the pixel already existing in the destination bitmap. If aBlend 
   is 'true', the drawn pixel are alpha-blended with the background, otherwise the 
   drawn pixel will overwrite the old content. */
void GraphicsCanvas_FillRectangle( GraphicsCanvas _this, XRect aClip, XRect aDstRect, 
  XColor aColorTL, XColor aColorTR, XColor aColorBR, XColor aColorBL, XBool aBlend )
{
  XHandle dstBitmap;
  XInt32 dstFrameNo;

  if ( _this->Super1.bitmap == 0 )
    ResourcesBitmap__Update( _this );

  if ( _this->Super1.bitmap == 0 )
    return;

  dstBitmap = _this->Super1.bitmap;
  dstFrameNo = _this->DstFrameNr;
  {
    EwFillRectangle((XBitmap*)dstBitmap, dstFrameNo, aClip, aDstRect, aColorTL, aColorTR,
                     aColorBR, aColorBL, aBlend );
  }
}

/* Variants derived from the class : 'Graphics::Canvas' */
EW_DEFINE_CLASS_VARIANTS( GraphicsCanvas )
EW_END_OF_CLASS_VARIANTS( GraphicsCanvas )

/* Virtual Method Table (VMT) for the class : 'Graphics::Canvas' */
EW_DEFINE_CLASS( GraphicsCanvas, ResourcesBitmap, OnDraw, OnDraw, InvalidArea, InvalidArea, 
                 InvalidArea, "Graphics::Canvas" )
  GraphicsCanvas_OnSetFrameSize,
  GraphicsCanvas_Update,
EW_END_OF_CLASS( GraphicsCanvas )

/* Initializer for the class 'Graphics::WarpMatrix' */
void GraphicsWarpMatrix__Init( GraphicsWarpMatrix _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_Super, aLink, aArg );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( GraphicsWarpMatrix );

  /* ... and initialize objects, variables, properties, etc. */
  _this->isIdentity = 1;
  _this->M11 = 1.000000f;
  _this->M22 = 1.000000f;
  _this->M33 = 1.000000f;
  _this->M44 = 1.000000f;
}

/* Re-Initializer for the class 'Graphics::WarpMatrix' */
void GraphicsWarpMatrix__ReInit( GraphicsWarpMatrix _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Graphics::WarpMatrix' */
void GraphicsWarpMatrix__Done( GraphicsWarpMatrix _this )
{
  /* Finalize this class */
  _this->_VMT = EW_CLASS( GraphicsWarpMatrix );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_Super );
}

/* 'C' function for method : 'Graphics::WarpMatrix.CalculateZ()' */
XBool GraphicsWarpMatrix_CalculateZ( GraphicsWarpMatrix _this, XFloat aX, XFloat 
  aY )
{
  XFloat z = (( aX * _this->M31 ) + ( aY * _this->M32 )) + _this->M34;
  XFloat w = (( aX * _this->M41 ) + ( aY * _this->M42 )) + _this->M44;

  if (( w != 0.000000f ) && ( w != 1.000000f ))
    z = z / w;

  _this->Z = z;
  return 1;
}

/* 'C' function for method : 'Graphics::WarpMatrix.Project()' */
XBool GraphicsWarpMatrix_Project( GraphicsWarpMatrix _this, XFloat aX, XFloat aY )
{
  XFloat eyeDistance = _this->EyeDistance;
  XFloat x;
  XFloat y;
  XFloat z;
  XFloat w;
  XFloat q;

  if ( eyeDistance < 0.000000f )
    return 0;

  x = (( aX * _this->M11 ) + ( aY * _this->M12 )) + _this->M14;
  y = (( aX * _this->M21 ) + ( aY * _this->M22 )) + _this->M24;
  z = (( aX * _this->M31 ) + ( aY * _this->M32 )) + _this->M34;
  w = (( aX * _this->M41 ) + ( aY * _this->M42 )) + _this->M44;
  q = 1.000000f;

  if (( w != 0.000000f ) && ( w != 1.000000f ))
  {
    x = x / w;
    y = y / w;
    z = z / w;
  }

  if ( eyeDistance != -z )
    q = q / ( z + eyeDistance );

  if ( eyeDistance != 0.000000f )
    q = q * eyeDistance;

  _this->X = x * q;
  _this->Y = y * q;
  _this->Z = z + eyeDistance;
  return 1;
}

/* 'C' function for method : 'Graphics::WarpMatrix.DeriveFromQuad()' */
GraphicsWarpMatrix GraphicsWarpMatrix_DeriveFromQuad( GraphicsWarpMatrix _this, 
  XFloat aX1, XFloat aY1, XFloat aX2, XFloat aY2, XFloat aX3, XFloat aY3, XFloat 
  aX4, XFloat aY4 )
{
  XFloat deltaX1 = aX2 - aX3;
  XFloat deltaY1 = aY2 - aY3;
  XFloat deltaX2 = aX4 - aX3;
  XFloat deltaY2 = aY4 - aY3;
  XFloat sumX = (( aX1 - aX2 ) + aX3 ) - aX4;
  XFloat sumY = (( aY1 - aY2 ) + aY3 ) - aY4;
  XFloat det = ( deltaX1 * deltaY2 ) - ( deltaY1 * deltaX2 );

  if ( det == 0.000000f )
    return 0;

  _this->M31 = (( sumX * deltaY2 ) - ( sumY * deltaX2 )) / det;
  _this->M32 = (( deltaX1 * sumY ) - ( deltaY1 * sumX )) / det;
  _this->M33 = 0.000000f;
  _this->M34 = 1.000000f;
  _this->M11 = ( aX2 - aX1 ) + ( _this->M31 * aX2 );
  _this->M12 = ( aX4 - aX1 ) + ( _this->M32 * aX4 );
  _this->M13 = 0.000000f;
  _this->M14 = aX1;
  _this->M21 = ( aY2 - aY1 ) + ( _this->M31 * aY2 );
  _this->M22 = ( aY4 - aY1 ) + ( _this->M32 * aY4 );
  _this->M23 = 0.000000f;
  _this->M24 = aY1;
  _this->M41 = 0.000000f;
  _this->M42 = 0.000000f;
  _this->M43 = 0.000000f;
  _this->M44 = 1.000000f;
  _this->isIdentity = 0;
  return _this;
}

/* Variants derived from the class : 'Graphics::WarpMatrix' */
EW_DEFINE_CLASS_VARIANTS( GraphicsWarpMatrix )
EW_END_OF_CLASS_VARIANTS( GraphicsWarpMatrix )

/* Virtual Method Table (VMT) for the class : 'Graphics::WarpMatrix' */
EW_DEFINE_CLASS( GraphicsWarpMatrix, XObject, _None, _None, _None, _None, _None, 
                 "Graphics::WarpMatrix" )
EW_END_OF_CLASS( GraphicsWarpMatrix )

/* Embedded Wizard */
