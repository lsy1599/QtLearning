#ifndef OCRGLOBAL_H
#define OCRGLOBAL_H

/* =================================================
 * This file is part of the TTK OCR project
 * Copyright (C) 2015 - 2019 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QMap>
#include <QSet>
#include <QVariant>
#include <QtCore/qglobal.h>

#ifdef Q_CC_GNU
#  pragma GCC diagnostic ignored "-Wunused-function"
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#  define OCR_GREATER_NEW
#  if QT_VERSION >= QT_VERSION_CHECK(5,2,0)
#    define OCR_WINEXTRAS
#  else
#    define OCR_NO_WINEXTRAS
#  endif
#else
#  define OCR_NO_WINEXTRAS
#endif

#ifdef QT_DEBUG
#   define TTK_DEBUG
#endif

//////////////////////////////////////
#ifdef __cplusplus
#  define OCR_CAST
#endif
//////////////////////////////////////

//////////////////////////////////////
///cast
///
#ifdef OCR_CAST
#  define MConst_cast(x,y) (const_cast< x >(y))
#else
#  define MConst_cast(x,y) ((x)(y))
#endif

#ifdef OCR_CAST
#  define MDynamic_cast(x,y) (dynamic_cast< x >(y))
#else
#  define MDynamic_cast(x,y) ((x)(y))
#endif

#ifdef OCR_CAST
#  define MReinterpret_cast(x,y) (reinterpret_cast< x >(y))
#else
#  define MReinterpret_cast(x,y) ((x)(y))
#endif

#ifdef OCR_CAST
#  define MStatic_cast(x,y) (static_cast< x >(y))
#else
#  define MStatic_cast(x,y) ((x)(y))
#endif

#ifdef OCR_CAST
#  define MObject_cast(x,y) (qobject_cast< x >(y))
#else
#  define MObject_cast(x,y) (qobject_cast< x >(y))
#endif

//////////////////////////////////////

#ifndef _MSC_VER
  //gcc version less than 3.4.0
  #if __GNUC__ <= 3 && __GNUC_MINOR__ <= 4
    #define STRCAT(a, b)    a##b
  #else
    #define STRCAT(a, b)    a b
  #endif
#else
#define STRCAT(a, b)    a b
#endif

#define TTK_DECLARE_LISTS(Class) \
    typedef QList<Class> Class##s;

#define TTK_DECLARE_FLAGS(Flags, Enum) \
    typedef QFlags<Enum> Flags;

//////////////////////////////////////

#ifndef OCR_NAMESPACE
#define OCR_NAMESPACE OCR
#endif //OCR_NAMESPACE

#if QT_VERSION <= QT_VERSION_CHECK(4,6,0)
#define OCR_NO_NAMESPACE_SUPPORT
#endif

#ifndef OCR_NO_NAMESPACE_SUPPORT
#define OCR_BEGIN_NAMESPACE namespace OCR_NAMESPACE {
#define OCR_END_NAMESPACE }
#define OCR_USE_NAMESPACE using namespace ::OCR_NAMESPACE;
#else
#define OCR_BEGIN_NAMESPACE
#define OCR_END_NAMESPACE
#define OCR_USE_NAMESPACE
#endif //OCR_NAMESPACE_SUPPORT
//////////////////////////////////////


/*! @brief The namespace of the application object.
 * @author Greedysky <greedysky@163.com>
 */
namespace OCRObject
{
    typedef signed char                        MInt8;         /* 8 bit signed */
    typedef unsigned char                      MUint8;        /* 8 bit unsigned */
    typedef short                              MInt16;        /* 16 bit signed */
    typedef unsigned short                     MUint16;       /* 16 bit unsigned */
    typedef int                                MInt32;        /* 32 bit signed */
    typedef unsigned int                       MUint32;       /* 32 bit unsigned */
    typedef long long                          MInt64;        /* 64 bit signed */
    typedef unsigned long long                 MUint64;       /* 64 bit unsigned */
    ///////////////////////////////////////

    typedef double                             MDouble;       /* double */
    typedef float                              MFloat;        /* float */
    typedef bool                               MBool;         /* bool */
    ///////////////////////////////////////

    typedef QList<QVariant>                    MVariantList;            /* variantlist */
    typedef QList<QStringList>                 MStringLists;            /* stringlists */
    typedef QList<int>                         MIntList;                /* intlist */
    typedef QList<MIntList>                    MIntLists;               /* intlists */
    typedef QSet<QVariant>                     MVariantSet;             /* variantset */
    typedef QSet<int>                          MIntSet;                 /* intset */
    typedef QSet<MIntSet>                      MIntSets;                /* intsets */
    typedef QMap<QVariant, QVariant>           MVariantsMap;            /* variantsmap */
    typedef QMap<QString, QVariant>            MStriantMap;             /* stringVariantMap */
    typedef QMap<QString, QString>             MStringsMap;             /* stringsMap */
    typedef QMap<QString, QStringList>         MStringsListMap;         /* stringStrlistsMap */
    typedef QMap<int, MIntList>                MIntsListMap;            /* intIntlistMap */
    typedef QMap<qint64, QString>              MIntStringMap;           /* intStrMap */
    typedef QMapIterator<QVariant, QVariant>   MVariantsMapIterator;    /* variantsmMapIterator */
    typedef QMapIterator<QString, QVariant>    MStriantMapIterator;     /* stringVariantMapIterator */
    typedef QMapIterator<QString, QString>     MStringsMapIterator;     /* stringsMapIterator */
    typedef QMapIterator<QString, QStringList> MStringsListMapIterator; /* stringStrlistsMapIterator */
    typedef QMapIterator<int, MIntList>        MIntsListMapIterator;    /* intIntlistMapIterator */
    typedef QMapIterator<qint64, QString>      MIntStringMapIterator;   /* intStrMapIterator */
    ///////////////////////////////////////
}


#endif // OCRGLOBAL_H
