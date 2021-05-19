/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
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
#include "_CoreGroup.h"
#include "_CoreTimer.h"
#include "_EffectsEffectTimerClass.h"
#include "_GraphicsCanvas.h"
#include "_GraphicsWarpMatrix.h"
#include "_ResourcesBitmap.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsWarpImage.h"
#include "_ViewsWarpView.h"
#include "Core.h"
#include "Effects.h"
#include "Views.h"

/* Constant values used in this 'C' module only. */
static const XColor _Const0000 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XPoint _Const0001 = { 0, 0 };
static const XRect _Const0002 = {{ 0, 0 }, { 0, 0 }};

#ifndef EW_DONT_CHECK_INDEX
  /* This function is used to check the indices when accessing an array.
     If you don't want this verification add the define EW_DONT_CHECK_INDEX
     to your Makefile or project settings. */
  static int EwCheckIndex( int aIndex, int aRange, const char* aFile, int aLine )
  {
    if (( aIndex < 0 ) || ( aIndex >= aRange ))
    {
      EwPrint( "[FATAL ERROR in %s:%d] Array index %d out of bounds %d",
                aFile, aLine, aIndex, aRange );
      EwPanic();
    }
    return aIndex;
  }

  #define EwCheckIndex( aIndex, aRange ) \
    EwCheckIndex( aIndex, aRange, __FILE__, __LINE__ )
#else
  #define EwCheckIndex( aIndex, aRange ) aIndex
#endif

/* Initializer for the class 'Views::Rectangle' */
void ViewsRectangle__Init( ViewsRectangle _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRectView__Init( &_this->_Super, aLink, aArg );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ViewsRectangle );

  /* ... and initialize objects, variables, properties, etc. */
  _this->ColorBL = _Const0000;
  _this->ColorBR = _Const0000;
  _this->ColorTR = _Const0000;
  _this->ColorTL = _Const0000;
}

/* Re-Initializer for the class 'Views::Rectangle' */
void ViewsRectangle__ReInit( ViewsRectangle _this )
{
  /* At first re-initialize the super class ... */
  CoreRectView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Views::Rectangle' */
void ViewsRectangle__Done( ViewsRectangle _this )
{
  /* Finalize this class */
  _this->_VMT = EW_CLASS( ViewsRectangle );

  /* Don't forget to deinitialize the super class ... */
  CoreRectView__Done( &_this->_Super );
}

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you never will need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void ViewsRectangle_Draw( ViewsRectangle _this, GraphicsCanvas aCanvas, XRect aClip, 
  XPoint aOffset, XInt32 aOpacity, XBool aBlend )
{
  aBlend = (XBool)( aBlend && (( _this->Super2.viewState & CoreViewStateAlphaBlended ) 
  == CoreViewStateAlphaBlended ));
  aOpacity = aOpacity + 1;

  if ( aOpacity < 256 )
  {
    XColor ctl = _this->ColorTL;
    XColor ctr = _this->ColorTR;
    XColor cbl = _this->ColorBL;
    XColor cbr = _this->ColorBR;
    ctl.Alpha = (XUInt8)(( aOpacity * ctl.Alpha ) >> 8 );
    ctr.Alpha = (XUInt8)(( aOpacity * ctr.Alpha ) >> 8 );
    cbl.Alpha = (XUInt8)(( aOpacity * cbl.Alpha ) >> 8 );
    cbr.Alpha = (XUInt8)(( aOpacity * cbr.Alpha ) >> 8 );
    GraphicsCanvas_FillRectangle( aCanvas, aClip, EwMoveRectPos( _this->Super1.Bounds, 
    aOffset ), ctl, ctr, cbr, cbl, aBlend );
  }
  else
    GraphicsCanvas_FillRectangle( aCanvas, aClip, EwMoveRectPos( _this->Super1.Bounds, 
    aOffset ), _this->ColorTL, _this->ColorTR, _this->ColorBR, _this->ColorBL, aBlend );
}

/* 'C' function for method : 'Views::Rectangle.OnSetColor()' */
void ViewsRectangle_OnSetColor( ViewsRectangle _this, XColor value )
{
  if ((( !EwCompColor( value, _this->ColorTL ) && !EwCompColor( value, _this->ColorTR )) 
      && !EwCompColor( value, _this->ColorBL )) && !EwCompColor( value, _this->ColorBR ))
    return;

  _this->ColorTL = value;
  _this->ColorTR = value;
  _this->ColorBL = value;
  _this->ColorBR = value;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* Variants derived from the class : 'Views::Rectangle' */
EW_DEFINE_CLASS_VARIANTS( ViewsRectangle )
EW_END_OF_CLASS_VARIANTS( ViewsRectangle )

/* Virtual Method Table (VMT) for the class : 'Views::Rectangle' */
EW_DEFINE_CLASS( ViewsRectangle, CoreRectView, _None, _None, _None, _None, _None, 
                 "Views::Rectangle" )
  CoreRectView_initLayoutContext,
  ViewsRectangle_Draw,
  CoreView_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreView_ChangeViewState,
  CoreRectView_OnSetBounds,
EW_END_OF_CLASS( ViewsRectangle )

/* Initializer for the class 'Views::Image' */
void ViewsImage__Init( ViewsImage _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRectView__Init( &_this->_Super, aLink, aArg );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ViewsImage );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Orientation = ViewsOrientationNormal;
  _this->Quality = 1;
  _this->ColorBL = _Const0000;
  _this->ColorBR = _Const0000;
  _this->ColorTR = _Const0000;
  _this->ColorTL = _Const0000;
  _this->Endless = 1;
  _this->Alignment = ViewsImageAlignmentAlignHorzCenter | ViewsImageAlignmentAlignVertCenter;
  _this->Opacity = 255;
}

/* Re-Initializer for the class 'Views::Image' */
void ViewsImage__ReInit( ViewsImage _this )
{
  /* At first re-initialize the super class ... */
  CoreRectView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Views::Image' */
void ViewsImage__Done( ViewsImage _this )
{
  /* Finalize this class */
  _this->_VMT = EW_CLASS( ViewsImage );

  /* Don't forget to deinitialize the super class ... */
  CoreRectView__Done( &_this->_Super );
}

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you never will need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void ViewsImage_Draw( ViewsImage _this, GraphicsCanvas aCanvas, XRect aClip, XPoint 
  aOffset, XInt32 aOpacity, XBool aBlend )
{
  XInt32 frameNr = _this->FrameNumber;
  XRect area;
  XPoint size;
  XEnum orient;
  XColor ctl;
  XColor ctr;
  XColor cbr;
  XColor cbl;
  XInt32 opacity;

  if ( _this->animFrameNumber >= 0 )
    frameNr = _this->animFrameNumber;

  if (( _this->Bitmap == 0 ) || ( frameNr >= _this->Bitmap->NoOfFrames ))
    return;

  ResourcesBitmap__Update( _this->Bitmap );
  area = ViewsImage_GetContentArea( _this );
  size = _this->Bitmap->FrameSize;
  orient = _this->Orientation;

  if ( EwIsRectEmpty( area ))
    return;

  ctl = _this->ColorTL;
  ctr = _this->ColorTR;
  cbr = _this->ColorBR;
  cbl = _this->ColorBL;
  opacity = ((( aOpacity + 1 ) * _this->Opacity ) >> 8 ) + 1;
  aBlend = (XBool)( aBlend && (( _this->Super2.viewState & CoreViewStateAlphaBlended ) 
  == CoreViewStateAlphaBlended ));

  if ( opacity < 256 )
  {
    ctl.Alpha = (XUInt8)(( ctl.Alpha * opacity ) >> 8 );
    ctr.Alpha = (XUInt8)(( ctr.Alpha * opacity ) >> 8 );
    cbr.Alpha = (XUInt8)(( cbr.Alpha * opacity ) >> 8 );
    cbl.Alpha = (XUInt8)(( cbl.Alpha * opacity ) >> 8 );
  }

  if ( !EwCompPoint( EwGetRectSize( area ), size ) && ( orient == ViewsOrientationNormal ))
    GraphicsCanvas_CopyBitmap( aCanvas, aClip, _this->Bitmap, frameNr, EwMoveRectPos( 
    _this->Super1.Bounds, aOffset ), EwMovePointNeg( _this->Super1.Bounds.Point1, 
    area.Point1 ), ctl, ctr, cbr, cbl, aBlend );
  else
    if ( orient == ViewsOrientationNormal )
      GraphicsCanvas_ScaleBitmap( aCanvas, aClip, _this->Bitmap, frameNr, EwMoveRectPos( 
      area, aOffset ), EwNewRect2Point( _Const0001, size ), ctl, ctr, cbr, cbl, 
      aBlend, _this->Quality );
    else
    {
      XFloat left = (XFloat)( area.Point1.X + aOffset.X );
      XFloat top = (XFloat)( area.Point1.Y + aOffset.Y );
      XFloat right = (XFloat)( area.Point2.X + aOffset.X );
      XFloat bottom = (XFloat)( area.Point2.Y + aOffset.Y );

      if ( orient == ViewsOrientationRotated_90 )
        GraphicsCanvas_WarpBitmap( aCanvas, aClip, _this->Bitmap, frameNr, left, 
        bottom, 1.000000f, left, top, 1.000000f, right, top, 1.000000f, right, bottom, 
        1.000000f, EwNewRect2Point( _Const0001, size ), cbl, ctl, ctr, cbr, aBlend, 
        _this->Quality );
      else
        if ( orient == ViewsOrientationRotated_180 )
          GraphicsCanvas_WarpBitmap( aCanvas, aClip, _this->Bitmap, frameNr, right, 
          bottom, 1.000000f, left, bottom, 1.000000f, left, top, 1.000000f, right, 
          top, 1.000000f, EwNewRect2Point( _Const0001, size ), cbr, cbl, ctl, ctr, 
          aBlend, _this->Quality );
        else
          if ( orient == ViewsOrientationRotated_270 )
            GraphicsCanvas_WarpBitmap( aCanvas, aClip, _this->Bitmap, frameNr, right, 
            top, 1.000000f, right, bottom, 1.000000f, left, bottom, 1.000000f, left, 
            top, 1.000000f, EwNewRect2Point( _Const0001, size ), ctr, cbr, cbl, 
            ctl, aBlend, _this->Quality );
    }
}

/* 'C' function for method : 'Views::Image.observerSlot()' */
void ViewsImage_observerSlot( ViewsImage _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ((( _this->AutoSize && ( _this->Bitmap != 0 )) && ( _this->Bitmap->FrameSize.X 
      > 0 )) && ( _this->Bitmap->FrameSize.Y > 0 ))
    CoreRectView__OnSetBounds( _this, EwMoveRectNeg( ViewsImage_GetContentArea( 
    _this ), _this->ScrollOffset ));

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Image.timerSlot()' */
void ViewsImage_timerSlot( ViewsImage _this, XObject sender )
{
  XInt32 frameNr;
  XInt32 period;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  frameNr = _this->animFrameNumber;
  period = 0;

  if ( _this->Bitmap != 0 )
    period = _this->Bitmap->NoOfFrames * _this->Bitmap->FrameDelay;

  if ((( _this->timer != 0 ) && ( _this->animFrameNumber < 0 )) && ( period > 0 ))
    _this->startTime = _this->timer->Time - ( _this->FrameNumber * _this->Bitmap->FrameDelay );

  if (( _this->timer != 0 ) && ( period > 0 ))
  {
    XInt32 time = (XInt32)( _this->timer->Time - _this->startTime );
    frameNr = time / _this->Bitmap->FrameDelay;

    if ( time >= period )
    {
      frameNr = frameNr % _this->Bitmap->NoOfFrames;
      _this->startTime = _this->timer->Time - ( time % period );

      if ( !_this->Endless )
      {
        frameNr = _this->Bitmap->NoOfFrames - 1;
        period = 0;
      }
    }
  }

  if ((( frameNr != _this->animFrameNumber ) && ( _this->Super2.Owner != 0 )) && 
      (( _this->Super2.viewState & CoreViewStateVisible ) == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );

  _this->animFrameNumber = frameNr;

  if (( period == 0 ) && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, ViewsImage_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
    EwSignal( _this->OnFinished, ((XObject)_this ));
  }
}

/* 'C' function for method : 'Views::Image.OnSetAnimated()' */
void ViewsImage_OnSetAnimated( ViewsImage _this, XBool value )
{
  if ( _this->Animated == value )
    return;

  _this->Animated = value;
  _this->animFrameNumber = -1;

  if ( !value && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, ViewsImage_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
  }

  if ( value )
  {
    _this->timer = ((CoreTimer)EwGetAutoObject( &EffectsEffectTimer, EffectsEffectTimerClass ));
    EwAttachObjObserver( EwNewSlot( _this, ViewsImage_timerSlot ), (XObject)_this->timer, 
      0 );
    EwPostSignal( EwNewSlot( _this, ViewsImage_timerSlot ), ((XObject)_this ));
  }

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* 'C' function for method : 'Views::Image.OnSetBitmap()' */
void ViewsImage_OnSetBitmap( ViewsImage _this, ResourcesBitmap value )
{
  if ( value == _this->Bitmap )
    return;

  if (( _this->Bitmap != 0 ) && _this->Bitmap->Mutable )
    EwDetachObjObserver( EwNewSlot( _this, ViewsImage_observerSlot ), (XObject)_this->Bitmap, 
      0 );

  _this->Bitmap = value;
  _this->animFrameNumber = -1;

  if (( value != 0 ) && value->Mutable )
    EwAttachObjObserver( EwNewSlot( _this, ViewsImage_observerSlot ), (XObject)value, 
      0 );

  if ( _this->Animated )
  {
    ViewsImage_OnSetAnimated( _this, 0 );
    ViewsImage_OnSetAnimated( _this, 1 );
  }

  if ((( _this->AutoSize && ( value != 0 )) && ( value->FrameSize.X > 0 )) && ( 
      value->FrameSize.Y > 0 ))
    CoreRectView__OnSetBounds( _this, EwMoveRectNeg( ViewsImage_GetContentArea( 
    _this ), _this->ScrollOffset ));

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, _this->Super1.Bounds );
}

/* The method GetContentArea() returns the position and the size of an area where 
   the view will show the bitmap. This area is expressed in coordinates relative 
   to the top-left corner of the view's @Owner. The method takes in account all 
   properties which do affect the position and the alignment of the bitmap, e.g. 
   @Alignment or @ScrollOffset. */
XRect ViewsImage_GetContentArea( ViewsImage _this )
{
  XEnum orient;
  XSet align;
  XPoint size;
  XRect bounds;
  XInt32 width;
  XInt32 height;
  XRect rd;
  XRect rs;

  if ( _this->Bitmap == 0 )
    return _Const0002;

  orient = _this->Orientation;
  align = _this->Alignment;
  size = _this->Bitmap->FrameSize;
  bounds = _this->Super1.Bounds;
  width = EwGetRectW( bounds );
  height = EwGetRectH( bounds );

  if (( size.X == 0 ) || ( size.Y == 0 ))
    return _Const0002;

  if (( orient == ViewsOrientationRotated_90 ) || ( orient == ViewsOrientationRotated_270 ))
  {
    width = height;
    height = EwGetRectW( bounds );
  }

  rd = EwNewRect( 0, 0, width, height );
  rs = rd;

  if ((( align & ViewsImageAlignmentScaleToFill ) == ViewsImageAlignmentScaleToFill ))
  {
    XInt32 scaleX = (( EwGetRectSize( rd ).X << 16 ) + ( size.X / 2 )) / size.X;
    XInt32 scaleY = (( EwGetRectSize( rd ).Y << 16 ) + ( size.Y / 2 )) / size.Y;
    XInt32 scale = scaleX;

    if ( scaleY > scale )
      scale = scaleY;

    rs = EwSetRectSize( rs, EwSetPointX( EwGetRectSize( rs ), (( size.X * scale ) 
    + 32768 ) >> 16 ));
    rs = EwSetRectSize( rs, EwSetPointY( EwGetRectSize( rs ), (( size.Y * scale ) 
    + 32768 ) >> 16 ));
  }
  else
    if ((( align & ViewsImageAlignmentScaleToFit ) == ViewsImageAlignmentScaleToFit ))
    {
      XInt32 scaleX = (( EwGetRectSize( rd ).X << 16 ) + ( size.X / 2 )) / size.X;
      XInt32 scaleY = (( EwGetRectSize( rd ).Y << 16 ) + ( size.Y / 2 )) / size.Y;
      XInt32 scale = scaleX;

      if ( scaleY < scale )
        scale = scaleY;

      rs = EwSetRectSize( rs, EwSetPointX( EwGetRectSize( rs ), (( size.X * scale ) 
      + 32768 ) >> 16 ));
      rs = EwSetRectSize( rs, EwSetPointY( EwGetRectSize( rs ), (( size.Y * scale ) 
      + 32768 ) >> 16 ));
    }
    else
      if ( !(( align & ViewsImageAlignmentStretchToFill ) == ViewsImageAlignmentStretchToFill ))
        rs = EwSetRectSize( rs, size );

  if ( EwGetRectSize( rs ).X != EwGetRectSize( rd ).X )
  {
    if ((( align & ViewsImageAlignmentAlignHorzRight ) == ViewsImageAlignmentAlignHorzRight ))
      rs = EwSetRectOrigin( rs, EwSetPointX( rs.Point1, rd.Point2.X - EwGetRectSize( 
      rs ).X ));
    else
      if ((( align & ViewsImageAlignmentAlignHorzCenter ) == ViewsImageAlignmentAlignHorzCenter ))
        rs = EwSetRectOrigin( rs, EwSetPointX( rs.Point1, ( rd.Point1.X + ( EwGetRectSize( 
        rd ).X / 2 )) - ( EwGetRectSize( rs ).X / 2 )));
  }

  if ( EwGetRectSize( rs ).Y != EwGetRectSize( rd ).Y )
  {
    if ((( align & ViewsImageAlignmentAlignVertBottom ) == ViewsImageAlignmentAlignVertBottom ))
      rs = EwSetRectOrigin( rs, EwSetPointY( rs.Point1, rd.Point2.Y - EwGetRectSize( 
      rs ).Y ));
    else
      if ((( align & ViewsImageAlignmentAlignVertCenter ) == ViewsImageAlignmentAlignVertCenter ))
        rs = EwSetRectOrigin( rs, EwSetPointY( rs.Point1, ( rd.Point1.Y + ( EwGetRectSize( 
        rd ).Y / 2 )) - ( EwGetRectSize( rs ).Y / 2 )));
  }

  if ( orient == ViewsOrientationNormal )
    rs = EwMoveRectPos( rs, bounds.Point1 );
  else
    if ( orient == ViewsOrientationRotated_90 )
    {
      XPoint org = EwNewPoint( bounds.Point1.X + rs.Point1.Y, bounds.Point2.Y - 
        rs.Point2.X );
      rs = EwNewRect2Point( org, EwMovePointPos( org, EwNewPoint( EwGetRectH( rs ), 
      EwGetRectW( rs ))));
    }
    else
      if ( orient == ViewsOrientationRotated_180 )
      {
        XPoint org = EwNewPoint( bounds.Point2.X - rs.Point2.X, bounds.Point2.Y 
          - rs.Point2.Y );
        rs = EwNewRect2Point( org, EwMovePointPos( org, EwGetRectSize( rs )));
      }
      else
        if ( orient == ViewsOrientationRotated_270 )
        {
          XPoint org = EwNewPoint( bounds.Point2.X - rs.Point2.Y, bounds.Point1.Y 
            + rs.Point1.X );
          rs = EwNewRect2Point( org, EwMovePointPos( org, EwNewPoint( EwGetRectH( 
          rs ), EwGetRectW( rs ))));
        }

  return EwMoveRectPos( rs, _this->ScrollOffset );
}

/* Variants derived from the class : 'Views::Image' */
EW_DEFINE_CLASS_VARIANTS( ViewsImage )
EW_END_OF_CLASS_VARIANTS( ViewsImage )

/* Virtual Method Table (VMT) for the class : 'Views::Image' */
EW_DEFINE_CLASS( ViewsImage, CoreRectView, timer, OnFinished, startTime, startTime, 
                 startTime, "Views::Image" )
  CoreRectView_initLayoutContext,
  ViewsImage_Draw,
  CoreView_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreView_ChangeViewState,
  CoreRectView_OnSetBounds,
EW_END_OF_CLASS( ViewsImage )

/* Initializer for the class 'Views::WarpView' */
void ViewsWarpView__Init( ViewsWarpView _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreQuadView__Init( &_this->_Super, aLink, aArg );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ViewsWarpView );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super2.viewState = CoreViewStateAlphaBlended | CoreViewStateVisible;
  _this->Shininess = 5.000000f;
  _this->Quality = 1;
}

/* Re-Initializer for the class 'Views::WarpView' */
void ViewsWarpView__ReInit( ViewsWarpView _this )
{
  /* At first re-initialize the super class ... */
  CoreQuadView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Views::WarpView' */
void ViewsWarpView__Done( ViewsWarpView _this )
{
  /* Finalize this class */
  _this->_VMT = EW_CLASS( ViewsWarpView );

  /* Don't forget to deinitialize the super class ... */
  CoreQuadView__Done( &_this->_Super );
}

/* 'C' function for method : 'Views::WarpView.OnSetPoint4()' */
void ViewsWarpView_OnSetPoint4( ViewsWarpView _this, XPoint value )
{
  if ( !EwCompPoint( value, _this->Super1.Point4 ))
    return;

  CoreQuadView_OnSetPoint4((CoreQuadView)_this, value );
  _this->vertices[ 3 ][ 0 ] = (XFloat)value.X;
  _this->vertices[ 3 ][ 1 ] = (XFloat)value.Y;
  _this->vertices[ 3 ][ 2 ] = 1.000000f;
  _this->newUpdateCase = 'E';
  _this->matrix = 0;
  EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::WarpView.OnSetPoint3()' */
void ViewsWarpView_OnSetPoint3( ViewsWarpView _this, XPoint value )
{
  if ( !EwCompPoint( value, _this->Super1.Point3 ))
    return;

  CoreQuadView_OnSetPoint3((CoreQuadView)_this, value );
  _this->vertices[ 2 ][ 0 ] = (XFloat)value.X;
  _this->vertices[ 2 ][ 1 ] = (XFloat)value.Y;
  _this->vertices[ 2 ][ 2 ] = 1.000000f;
  _this->newUpdateCase = 'E';
  _this->matrix = 0;
  EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::WarpView.OnSetPoint2()' */
void ViewsWarpView_OnSetPoint2( ViewsWarpView _this, XPoint value )
{
  if ( !EwCompPoint( value, _this->Super1.Point2 ))
    return;

  CoreQuadView_OnSetPoint2((CoreQuadView)_this, value );
  _this->vertices[ 1 ][ 0 ] = (XFloat)value.X;
  _this->vertices[ 1 ][ 1 ] = (XFloat)value.Y;
  _this->vertices[ 1 ][ 2 ] = 1.000000f;
  _this->newUpdateCase = 'E';
  _this->matrix = 0;
  EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::WarpView.OnSetPoint1()' */
void ViewsWarpView_OnSetPoint1( ViewsWarpView _this, XPoint value )
{
  if ( !EwCompPoint( value, _this->Super1.Point1 ))
    return;

  CoreQuadView_OnSetPoint1((CoreQuadView)_this, value );
  _this->vertices[ 0 ][ 0 ] = (XFloat)value.X;
  _this->vertices[ 0 ][ 1 ] = (XFloat)value.Y;
  _this->vertices[ 0 ][ 2 ] = 1.000000f;
  _this->newUpdateCase = 'E';
  _this->matrix = 0;
  EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
}

/* 'C' function for method : 'Views::WarpView.calculateLight()' */
void ViewsWarpView_calculateLight( ViewsWarpView _this )
{
  XFloat lx;
  XFloat ly;
  XFloat lz;
  XFloat ax;
  XFloat ay;
  XFloat az;
  XFloat bx;
  XFloat by;
  XFloat bz;
  XFloat nx;
  XFloat ny;
  XFloat nz;
  XFloat nlen;
  XInt32 i;

  if ( _this->LightingEffect == 0.000000f )
    return;

  lx = 240.000000f;
  ly = 240.000000f;
  lz = -10000000.000000f;
  ax = _this->vertices[ 1 ][ 0 ] - _this->vertices[ 0 ][ 0 ];
  ay = _this->vertices[ 1 ][ 1 ] - _this->vertices[ 0 ][ 1 ];
  az = _this->vertices[ 1 ][ 2 ] - _this->vertices[ 0 ][ 2 ];
  bx = _this->vertices[ 3 ][ 0 ] - _this->vertices[ 0 ][ 0 ];
  by = _this->vertices[ 3 ][ 1 ] - _this->vertices[ 0 ][ 1 ];
  bz = _this->vertices[ 3 ][ 2 ] - _this->vertices[ 0 ][ 2 ];
  nx = ( ay * bz ) - ( az * by );
  ny = ( az * bx ) - ( ax * bz );
  nz = ( ax * by ) - ( ay * bx );
  nlen = EwMathSqrt((( nx * nx ) + ( ny * ny )) + ( nz * nz ));

  if ( nlen > 0.000000f )
  {
    nlen = 1.000000f / nlen;
    nx = nx * nlen;
    ny = ny * nlen;
    nz = nz * nlen;
  }

  for ( i = 0; i < 4; i = i + 1 )
  {
    XFloat vlx = _this->vertices[ EwCheckIndex( i, 4 )][ 0 ] - lx;
    XFloat vly = _this->vertices[ EwCheckIndex( i, 4 )][ 1 ] - ly;
    XFloat vlz = _this->vertices[ EwCheckIndex( i, 4 )][ 2 ] - lz;
    XFloat vllen = EwMathSqrt((( vlx * vlx ) + ( vly * vly )) + ( vlz * vlz ));
    XFloat light;

    if ( vllen > 0.000000f )
    {
      vllen = 1.000000f / vllen;
      vlx = vlx * vllen;
      vly = vly * vllen;
      vlz = vlz * vllen;
    }

    light = (( vlx * nx ) + ( vly * ny )) + ( vlz * nz );

    if ( light < 0.000000f )
      light = -light;

    light = EwMathPow( light, _this->Shininess );
    light = (( _this->LightingEffect * light ) + 1.000000f ) - _this->LightingEffect;
    _this->lighting[ EwCheckIndex( i, 4 )] = (XInt32)( light * 257.000000f );

    if ( _this->lighting[ EwCheckIndex( i, 4 )] > 256 )
      _this->lighting[ EwCheckIndex( i, 4 )] = 256;
  }
}

/* 'C' function for method : 'Views::WarpView.update()' */
void ViewsWarpView_update( ViewsWarpView _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->newUpdateCase == 0x0000 )
    return;

  if ( _this->newUpdateCase == 'E' )
  {
    GraphicsWarpMatrix m = EwNewObject( GraphicsWarpMatrix, 0 );
    m = GraphicsWarpMatrix_DeriveFromQuad( m, _this->vertices[ 0 ][ 0 ], _this->vertices[ 
    0 ][ 1 ], _this->vertices[ 1 ][ 0 ], _this->vertices[ 1 ][ 1 ], _this->vertices[ 
    2 ][ 0 ], _this->vertices[ 2 ][ 1 ], _this->vertices[ 3 ][ 0 ], _this->vertices[ 
    3 ][ 1 ]);

    if ( m != 0 )
    {
      GraphicsWarpMatrix_CalculateZ( m, 0.000000f, 0.000000f );
      _this->vertices[ 0 ][ 2 ] = m->Z * 240.000000f;
      GraphicsWarpMatrix_CalculateZ( m, 1.000000f, 0.000000f );
      _this->vertices[ 1 ][ 2 ] = m->Z * 240.000000f;
      GraphicsWarpMatrix_CalculateZ( m, 1.000000f, 1.000000f );
      _this->vertices[ 2 ][ 2 ] = m->Z * 240.000000f;
      GraphicsWarpMatrix_CalculateZ( m, 0.000000f, 1.000000f );
      _this->vertices[ 3 ][ 2 ] = m->Z * 240.000000f;
    }

    ViewsWarpView_calculateLight( _this );
  }

  if (((( _this->newUpdateCase == 'M' ) && ( _this->matrix != 0 )) && ( _this->bitmapSize.X 
      != 0 )) && ( _this->bitmapSize.Y != 0 ))
  {
    XRect sourceArea = EwIntersectRect2( _this->SourceArea, EwNewRect2Point( _Const0001, 
      _this->bitmapSize ));
    XPoint sourceAnchor = _this->SourceAnchor;
    XFloat l = (XFloat)( sourceArea.Point1.X - sourceAnchor.X );
    XFloat r = (XFloat)( sourceArea.Point2.X - sourceAnchor.X );
    XFloat t = (XFloat)( sourceArea.Point1.Y - sourceAnchor.Y );
    XFloat b = (XFloat)( sourceArea.Point2.Y - sourceAnchor.Y );
    GraphicsWarpMatrix_Project( _this->matrix, l, t );
    _this->vertices[ 0 ][ 0 ] = _this->matrix->X + _this->dstPosX;
    _this->vertices[ 0 ][ 1 ] = _this->matrix->Y + _this->dstPosY;
    _this->vertices[ 0 ][ 2 ] = _this->matrix->Z;
    GraphicsWarpMatrix_Project( _this->matrix, r, t );
    _this->vertices[ 1 ][ 0 ] = _this->matrix->X + _this->dstPosX;
    _this->vertices[ 1 ][ 1 ] = _this->matrix->Y + _this->dstPosY;
    _this->vertices[ 1 ][ 2 ] = _this->matrix->Z;
    GraphicsWarpMatrix_Project( _this->matrix, r, b );
    _this->vertices[ 2 ][ 0 ] = _this->matrix->X + _this->dstPosX;
    _this->vertices[ 2 ][ 1 ] = _this->matrix->Y + _this->dstPosY;
    _this->vertices[ 2 ][ 2 ] = _this->matrix->Z;
    GraphicsWarpMatrix_Project( _this->matrix, l, b );
    _this->vertices[ 3 ][ 0 ] = _this->matrix->X + _this->dstPosX;
    _this->vertices[ 3 ][ 1 ] = _this->matrix->Y + _this->dstPosY;
    _this->vertices[ 3 ][ 2 ] = _this->matrix->Z;

    if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
        == CoreViewStateVisible ))
      CoreGroup__InvalidateArea( _this->Super2.Owner, CoreView__GetExtent( _this ));

    _this->Super1.Point1 = EwNewPoint((XInt32)( _this->vertices[ 0 ][ 0 ] + 0.500000f ), 
    (XInt32)( _this->vertices[ 0 ][ 1 ] + 0.500000f ));
    _this->Super1.Point2 = EwNewPoint((XInt32)( _this->vertices[ 1 ][ 0 ] + 0.500000f ), 
    (XInt32)( _this->vertices[ 1 ][ 1 ] + 0.500000f ));
    _this->Super1.Point3 = EwNewPoint((XInt32)( _this->vertices[ 2 ][ 0 ] + 0.500000f ), 
    (XInt32)( _this->vertices[ 2 ][ 1 ] + 0.500000f ));
    _this->Super1.Point4 = EwNewPoint((XInt32)( _this->vertices[ 3 ][ 0 ] + 0.500000f ), 
    (XInt32)( _this->vertices[ 3 ][ 1 ] + 0.500000f ));
    ViewsWarpView_calculateLight( _this );
  }

  _this->oldUpdateCase = _this->newUpdateCase;
  _this->newUpdateCase = 0x0000;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, CoreView__GetExtent( _this ));
}

/* 'C' function for method : 'Views::WarpView.OnSetSourceAnchor()' */
void ViewsWarpView_OnSetSourceAnchor( ViewsWarpView _this, XPoint value )
{
  if ( !EwCompPoint( value, _this->SourceAnchor ))
    return;

  _this->SourceAnchor = value;

  if (( _this->oldUpdateCase != 'E' ) && ( _this->newUpdateCase == 0x0000 ))
  {
    _this->newUpdateCase = _this->oldUpdateCase;
    EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
  }
}

/* The method RotateAndScale() performs a 2D rotation and scaling of the source 
   image. The transformation is performed around a reference position specified 
   in the property @SourceAnchor. This allows e.g. a rotation around the center 
   of the image, etc. The rotation angle is passed in the parameter aAngle as a 
   value in the range 0 .. 360°. The values passed in the parameters aScaleX and 
   aScaleY determine additional scaling factors for the image in the horizontal 
   and vertical direction. If no scaling should be performed, the value 1.0 can 
   be passed to these parameters. In contrast, if no rotation is desired, 0.0 can 
   be passed to the parameter aAngle.
   The transformed image appears on the screen at the position aDstPos relative 
   to the top-left corner of this view's @Owner. The view itself takes the shape 
   resulting from this transformation and adapts its @Point1 .. @Point4 coordinates 
   accordingly. More sophisticated 2D and 3D transformations are performed by the 
   method @Warp3D(). */
void ViewsWarpView_RotateAndScale( ViewsWarpView _this, XPoint aDstPos, XFloat aAngle, 
  XFloat aScaleX, XFloat aScaleY )
{
  XRect sourceArea;
  XPoint sourceAnchor;
  XFloat l;
  XFloat r;
  XFloat t;
  XFloat b;
  XFloat cosA;
  XFloat sinA;
  XFloat l_cosA;
  XFloat l_sinA;
  XFloat r_cosA;
  XFloat r_sinA;
  XFloat t_cosA;
  XFloat t_sinA;
  XFloat b_cosA;
  XFloat b_sinA;
  XFloat dstX;
  XFloat dstY;

  if (( _this->bitmapSize.X == 0 ) || ( _this->bitmapSize.Y == 0 ))
    return;

  sourceArea = EwIntersectRect2( _this->SourceArea, EwNewRect2Point( _Const0001, 
  _this->bitmapSize ));
  sourceAnchor = _this->SourceAnchor;
  l = (XFloat)( sourceArea.Point1.X - sourceAnchor.X ) * aScaleX;
  r = (XFloat)( sourceArea.Point2.X - sourceAnchor.X ) * aScaleX;
  t = (XFloat)( sourceArea.Point1.Y - sourceAnchor.Y ) * aScaleY;
  b = (XFloat)( sourceArea.Point2.Y - sourceAnchor.Y ) * aScaleY;
  cosA = EwMathCos( aAngle );
  sinA = EwMathSin( aAngle );
  l_cosA = l * cosA;
  l_sinA = l * sinA;
  r_cosA = r * cosA;
  r_sinA = r * sinA;
  t_cosA = t * cosA;
  t_sinA = t * sinA;
  b_cosA = b * cosA;
  b_sinA = b * sinA;
  dstX = (XFloat)aDstPos.X;
  dstY = (XFloat)aDstPos.Y;
  _this->vertices[ 0 ][ 0 ] = ( dstX + l_cosA ) + t_sinA;
  _this->vertices[ 0 ][ 1 ] = ( dstY - l_sinA ) + t_cosA;
  _this->vertices[ 1 ][ 0 ] = ( dstX + r_cosA ) + t_sinA;
  _this->vertices[ 1 ][ 1 ] = ( dstY - r_sinA ) + t_cosA;
  _this->vertices[ 2 ][ 0 ] = ( dstX + r_cosA ) + b_sinA;
  _this->vertices[ 2 ][ 1 ] = ( dstY - r_sinA ) + b_cosA;
  _this->vertices[ 3 ][ 0 ] = ( dstX + l_cosA ) + b_sinA;
  _this->vertices[ 3 ][ 1 ] = ( dstY - l_sinA ) + b_cosA;
  _this->vertices[ 0 ][ 2 ] = 1.000000f;
  _this->vertices[ 1 ][ 2 ] = 1.000000f;
  _this->vertices[ 2 ][ 2 ] = 1.000000f;
  _this->vertices[ 3 ][ 2 ] = 1.000000f;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, CoreView__GetExtent( _this ));

  _this->Super1.Point1 = EwNewPoint((XInt32)( _this->vertices[ 0 ][ 0 ] + 0.500000f ), 
  (XInt32)( _this->vertices[ 0 ][ 1 ] + 0.500000f ));
  _this->Super1.Point2 = EwNewPoint((XInt32)( _this->vertices[ 1 ][ 0 ] + 0.500000f ), 
  (XInt32)( _this->vertices[ 1 ][ 1 ] + 0.500000f ));
  _this->Super1.Point3 = EwNewPoint((XInt32)( _this->vertices[ 2 ][ 0 ] + 0.500000f ), 
  (XInt32)( _this->vertices[ 2 ][ 1 ] + 0.500000f ));
  _this->Super1.Point4 = EwNewPoint((XInt32)( _this->vertices[ 3 ][ 0 ] + 0.500000f ), 
  (XInt32)( _this->vertices[ 3 ][ 1 ] + 0.500000f ));
  _this->oldUpdateCase = 'E';
  _this->newUpdateCase = 0x0000;
  _this->matrix = 0;

  if (( _this->Super2.Owner != 0 ) && (( _this->Super2.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super2.Owner, CoreView__GetExtent( _this ));

  ViewsWarpView_calculateLight( _this );
}

/* Variants derived from the class : 'Views::WarpView' */
EW_DEFINE_CLASS_VARIANTS( ViewsWarpView )
EW_END_OF_CLASS_VARIANTS( ViewsWarpView )

/* Virtual Method Table (VMT) for the class : 'Views::WarpView' */
EW_DEFINE_CLASS( ViewsWarpView, CoreQuadView, matrix, dstPosY, dstPosY, dstPosY, 
                 dstPosY, "Views::WarpView" )
  CoreQuadView_initLayoutContext,
  CoreView_Draw,
  CoreView_CursorHitTest,
  CoreQuadView_ArrangeView,
  CoreQuadView_MoveView,
  CoreQuadView_GetExtent,
  CoreView_ChangeViewState,
  ViewsWarpView_OnSetPoint4,
  ViewsWarpView_OnSetPoint3,
  ViewsWarpView_OnSetPoint2,
  ViewsWarpView_OnSetPoint1,
EW_END_OF_CLASS( ViewsWarpView )

/* Initializer for the class 'Views::WarpImage' */
void ViewsWarpImage__Init( ViewsWarpImage _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  ViewsWarpView__Init( &_this->_Super, aLink, aArg );

  /* Setup the VMT pointer */
  _this->_VMT = EW_CLASS( ViewsWarpImage );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Color4 = _Const0000;
  _this->Color3 = _Const0000;
  _this->Color2 = _Const0000;
  _this->Color1 = _Const0000;
  _this->Endless = 1;
  _this->Opacity = 255;
}

/* Re-Initializer for the class 'Views::WarpImage' */
void ViewsWarpImage__ReInit( ViewsWarpImage _this )
{
  /* At first re-initialize the super class ... */
  ViewsWarpView__ReInit( &_this->_Super );
}

/* Finalizer method for the class 'Views::WarpImage' */
void ViewsWarpImage__Done( ViewsWarpImage _this )
{
  /* Finalize this class */
  _this->_VMT = EW_CLASS( ViewsWarpImage );

  /* Don't forget to deinitialize the super class ... */
  ViewsWarpView__Done( &_this->_Super );
}

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you never will need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void ViewsWarpImage_Draw( ViewsWarpImage _this, GraphicsCanvas aCanvas, XRect aClip, 
  XPoint aOffset, XInt32 aOpacity, XBool aBlend )
{
  XInt32 frameNr = _this->FrameNumber;
  XColor c1;
  XColor c2;
  XColor c3;
  XColor c4;
  XInt32 opacity;
  XFloat ofsX;
  XFloat ofsY;
  XRect area;

  if ( _this->animFrameNumber >= 0 )
    frameNr = _this->animFrameNumber;

  if (( _this->Bitmap == 0 ) || ( frameNr >= _this->Bitmap->NoOfFrames ))
    return;

  ResourcesBitmap__Update( _this->Bitmap );
  c1 = _this->Color1;
  c2 = _this->Color2;
  c3 = _this->Color3;
  c4 = _this->Color4;
  opacity = ((( aOpacity + 1 ) * _this->Opacity ) >> 8 ) + 1;
  ofsX = (XFloat)aOffset.X;
  ofsY = (XFloat)aOffset.Y;
  area = EwIntersectRect2( _this->Super1.SourceArea, EwNewRect2Point( _Const0001, 
  _this->Super1.bitmapSize ));
  aBlend = (XBool)( aBlend && (( _this->Super3.viewState & CoreViewStateAlphaBlended ) 
  == CoreViewStateAlphaBlended ));

  if ( opacity < 256 )
  {
    c1.Alpha = (XUInt8)(( c1.Alpha * opacity ) >> 8 );
    c2.Alpha = (XUInt8)(( c2.Alpha * opacity ) >> 8 );
    c3.Alpha = (XUInt8)(( c3.Alpha * opacity ) >> 8 );
    c4.Alpha = (XUInt8)(( c4.Alpha * opacity ) >> 8 );
  }

  if ( _this->Super1.LightingEffect > 0.000000f )
  {
    if ( _this->Super1.lighting[ 0 ] < 256 )
      c1.Alpha = (XUInt8)(( c1.Alpha * _this->Super1.lighting[ 0 ]) >> 8 );

    if ( _this->Super1.lighting[ 1 ] < 256 )
      c2.Alpha = (XUInt8)(( c2.Alpha * _this->Super1.lighting[ 1 ]) >> 8 );

    if ( _this->Super1.lighting[ 2 ] < 256 )
      c3.Alpha = (XUInt8)(( c3.Alpha * _this->Super1.lighting[ 2 ]) >> 8 );

    if ( _this->Super1.lighting[ 3 ] < 256 )
      c4.Alpha = (XUInt8)(( c4.Alpha * _this->Super1.lighting[ 3 ]) >> 8 );
  }

  aClip = EwIntersectRect2( aClip, EwMoveRectPos( _this->Super1.Clipping, aOffset ));
  GraphicsCanvas_WarpBitmap( aCanvas, aClip, _this->Bitmap, frameNr, _this->Super1.vertices[ 
  0 ][ 0 ] + ofsX, _this->Super1.vertices[ 0 ][ 1 ] + ofsY, _this->Super1.vertices[ 
  0 ][ 2 ], _this->Super1.vertices[ 1 ][ 0 ] + ofsX, _this->Super1.vertices[ 1 ][ 
  1 ] + ofsY, _this->Super1.vertices[ 1 ][ 2 ], _this->Super1.vertices[ 2 ][ 0 ] 
  + ofsX, _this->Super1.vertices[ 2 ][ 1 ] + ofsY, _this->Super1.vertices[ 2 ][ 
  2 ], _this->Super1.vertices[ 3 ][ 0 ] + ofsX, _this->Super1.vertices[ 3 ][ 1 ] 
  + ofsY, _this->Super1.vertices[ 3 ][ 2 ], area, c1, c2, c3, c4, aBlend, _this->Super1.Quality );
}

/* 'C' function for method : 'Views::WarpImage.observerSlot()' */
void ViewsWarpImage_observerSlot( ViewsWarpImage _this, XObject sender )
{
  XPoint oldBitmapSize;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  oldBitmapSize = _this->Super1.bitmapSize;

  if ( _this->Bitmap != 0 )
    _this->Super1.bitmapSize = _this->Bitmap->FrameSize;
  else
    _this->Super1.bitmapSize = _Const0001;

  if ((( !EwCompPoint( oldBitmapSize, _this->Super1.bitmapSize ) || (( _this->Super1.oldUpdateCase 
      == 'E' ) && ( _this->Super1.newUpdateCase == 0x0000 ))) && ( _this->Super3.Owner 
      != 0 )) && (( _this->Super3.viewState & CoreViewStateVisible ) == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super3.Owner, CoreView__GetExtent( _this ));

  if ((( _this->Super1.oldUpdateCase != 'E' ) && ( _this->Super1.newUpdateCase == 
      0x0000 )) && EwCompPoint( oldBitmapSize, _this->Super1.bitmapSize ))
  {
    _this->Super1.newUpdateCase = _this->Super1.oldUpdateCase;
    EwPostSignal( EwNewSlot( _this, ViewsWarpView_update ), ((XObject)_this ));
  }
}

/* 'C' function for method : 'Views::WarpImage.timerSlot()' */
void ViewsWarpImage_timerSlot( ViewsWarpImage _this, XObject sender )
{
  XInt32 frameNr;
  XInt32 period;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  frameNr = _this->animFrameNumber;
  period = 0;

  if ( _this->Bitmap != 0 )
    period = _this->Bitmap->NoOfFrames * _this->Bitmap->FrameDelay;

  if ((( _this->timer != 0 ) && ( _this->animFrameNumber < 0 )) && ( period > 0 ))
    _this->startTime = _this->timer->Time - ( _this->FrameNumber * _this->Bitmap->FrameDelay );

  if (( _this->timer != 0 ) && ( period > 0 ))
  {
    XInt32 time = (XInt32)( _this->timer->Time - _this->startTime );
    frameNr = time / _this->Bitmap->FrameDelay;

    if ( time >= period )
    {
      frameNr = frameNr % _this->Bitmap->NoOfFrames;
      _this->startTime = _this->timer->Time - ( time % period );

      if ( !_this->Endless )
      {
        frameNr = _this->Bitmap->NoOfFrames - 1;
        period = 0;
      }
    }
  }

  if ((( frameNr != _this->animFrameNumber ) && ( _this->Super3.Owner != 0 )) && 
      (( _this->Super3.viewState & CoreViewStateVisible ) == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super3.Owner, CoreView__GetExtent( _this ));

  _this->animFrameNumber = frameNr;

  if (( period == 0 ) && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, ViewsWarpImage_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
    EwSignal( _this->OnFinished, ((XObject)_this ));
  }
}

/* 'C' function for method : 'Views::WarpImage.OnSetAnimated()' */
void ViewsWarpImage_OnSetAnimated( ViewsWarpImage _this, XBool value )
{
  if ( _this->Animated == value )
    return;

  _this->Animated = value;
  _this->animFrameNumber = -1;

  if ( !value && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, ViewsWarpImage_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
  }

  if ( value )
  {
    _this->timer = ((CoreTimer)EwGetAutoObject( &EffectsEffectTimer, EffectsEffectTimerClass ));
    EwAttachObjObserver( EwNewSlot( _this, ViewsWarpImage_timerSlot ), (XObject)_this->timer, 
      0 );
    EwPostSignal( EwNewSlot( _this, ViewsWarpImage_timerSlot ), ((XObject)_this ));
  }

  if (( _this->Super3.Owner != 0 ) && (( _this->Super3.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super3.Owner, CoreView__GetExtent( _this ));
}

/* 'C' function for method : 'Views::WarpImage.OnSetColor()' */
void ViewsWarpImage_OnSetColor( ViewsWarpImage _this, XColor value )
{
  if ((( !EwCompColor( value, _this->Color1 ) && !EwCompColor( value, _this->Color2 )) 
      && !EwCompColor( value, _this->Color3 )) && !EwCompColor( value, _this->Color4 ))
    return;

  _this->Color1 = value;
  _this->Color2 = value;
  _this->Color3 = value;
  _this->Color4 = value;

  if (( _this->Super3.Owner != 0 ) && (( _this->Super3.viewState & CoreViewStateVisible ) 
      == CoreViewStateVisible ))
    CoreGroup__InvalidateArea( _this->Super3.Owner, CoreView__GetExtent( _this ));
}

/* 'C' function for method : 'Views::WarpImage.OnSetBitmap()' */
void ViewsWarpImage_OnSetBitmap( ViewsWarpImage _this, ResourcesBitmap value )
{
  if ( value == _this->Bitmap )
    return;

  if (( _this->Bitmap != 0 ) && _this->Bitmap->Mutable )
    EwDetachObjObserver( EwNewSlot( _this, ViewsWarpImage_observerSlot ), (XObject)_this->Bitmap, 
      0 );

  _this->Bitmap = value;
  _this->animFrameNumber = -1;

  if (( value != 0 ) && value->Mutable )
    EwAttachObjObserver( EwNewSlot( _this, ViewsWarpImage_observerSlot ), (XObject)value, 
      0 );

  if ( _this->Animated )
  {
    ViewsWarpImage_OnSetAnimated( _this, 0 );
    ViewsWarpImage_OnSetAnimated( _this, 1 );
  }

  EwSignal( EwNewSlot( _this, ViewsWarpImage_observerSlot ), ((XObject)_this ));
}

/* Variants derived from the class : 'Views::WarpImage' */
EW_DEFINE_CLASS_VARIANTS( ViewsWarpImage )
EW_END_OF_CLASS_VARIANTS( ViewsWarpImage )

/* Virtual Method Table (VMT) for the class : 'Views::WarpImage' */
EW_DEFINE_CLASS( ViewsWarpImage, ViewsWarpView, timer, OnFinished, startTime, startTime, 
                 startTime, "Views::WarpImage" )
  CoreQuadView_initLayoutContext,
  ViewsWarpImage_Draw,
  CoreView_CursorHitTest,
  CoreQuadView_ArrangeView,
  CoreQuadView_MoveView,
  CoreQuadView_GetExtent,
  CoreView_ChangeViewState,
  ViewsWarpView_OnSetPoint4,
  ViewsWarpView_OnSetPoint3,
  ViewsWarpView_OnSetPoint2,
  ViewsWarpView_OnSetPoint1,
EW_END_OF_CLASS( ViewsWarpImage )

/* Embedded Wizard */
