#define PCL_NO_PRECOMPILE
#include <pcl/memory.h>
#include <pcl/pcl_macros.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>

struct _PointXYZFace
{
  PCL_ADD_POINT4D;
  int face;
  PCL_MAKE_ALIGNED_OPERATOR_NEW
};

struct EIGEN_ALIGN16 PointXYZFace : public _PointXYZFace
{
  inline PointXYZFace (const _PointXYZFace &p): PointXYZFace(p.x, p.y, p.z, p.face) {}

  inline PointXYZFace (): PointXYZFace(0.f, 0.f, 0.f, -1) {}

  inline PointXYZFace (float _x, float _y, float _z, int _face)
  {
  x = _x; y = _y; z = _z; face = _face;
  data[3] = 1.0f;
  }

  PCL_MAKE_ALIGNED_OPERATOR_NEW
};


struct EIGEN_ALIGN16 _PointXYZRGBFace
{
  PCL_ADD_POINT4D;
  PCL_ADD_RGB;
  int face;
  PCL_MAKE_ALIGNED_OPERATOR_NEW
};

struct EIGEN_ALIGN16 PointXYZRGBFace : public _PointXYZRGBFace
{
  inline PointXYZRGBFace (const _PointXYZRGBFace &p)
  {
    x = p.x; y = p.y; z = p.z; data[3] = 1.0f;
    rgb = p.rgb;
    face = p.face;
  }

  inline PointXYZRGBFace (): PointXYZRGBFace (0.f, 0.f, 0.f) {}

  inline PointXYZRGBFace (std::uint8_t _r, std::uint8_t _g, std::uint8_t _b):
    PointXYZRGBFace (0.f, 0.f, 0.f, _r, _g, _b, -1) {}

  inline PointXYZRGBFace (float _x, float _y, float _z):
    PointXYZRGBFace (_x, _y, _z, 0, 0, 0, -1) {}

  inline PointXYZRGBFace (float _x, float _y, float _z,
                        std::uint8_t _r, std::uint8_t _g, std::uint8_t _b, int _face)
  {
    x = _x; y = _y; z = _z;
    data[3] = 1.0f;
    r = _r; g = _g; b = _b;
    a = 255;
    face = _face;
  }
  PCL_MAKE_ALIGNED_OPERATOR_NEW
};


struct EIGEN_ALIGN16 _PointNormalFace
{
    PCL_ADD_POINT4D;
    PCL_ADD_NORMAL4D;
    union
    {
    struct
    {
        float curvature;
    };
    float data_c[4];
    };
    int face;
    PCL_MAKE_ALIGNED_OPERATOR_NEW
};
  
struct PointNormalFace : public _PointNormalFace
{
  inline PointNormalFace (const _PointNormalFace &p)
  {
    x = p.x; y = p.y; z = p.z; data[3] = 1.0f;
    normal_x = p.normal_x; normal_y = p.normal_y; normal_z = p.normal_z; data_n[3] = 0.0f;
    curvature = p.curvature;
    face = p.face;
  }

  inline PointNormalFace (float _curvature = 0.f): PointNormalFace (0.f, 0.f, 0.f, 0.f, 0.f, 0.f, _curvature, -1) {}

  inline PointNormalFace (float _x, float _y, float _z):
  PointNormalFace (_x, _y, _z, 0.f, 0.f, 0.f, 0.f, -1) {}

  inline PointNormalFace (float _x, float _y, float _z, float n_x, float n_y, float n_z, float _curvature, int _face)
  {
    x = _x; y = _y; z = _z;
    data[3] = 1.0f;
    normal_x = n_x; normal_y = n_y; normal_z = n_z;
    data_n[3] = 0.0f;
    curvature = _curvature;
    face = _face;
  }
};


struct EIGEN_ALIGN16 _PointXYZRGBNormalFace
{
    PCL_ADD_POINT4D;
    PCL_ADD_NORMAL4D;
    union
    {
    struct
    {
        PCL_ADD_UNION_RGB;
        float curvature;
    };
    float data_c[4];
    };
    PCL_ADD_EIGEN_MAPS_RGB;
    int face;
    PCL_MAKE_ALIGNED_OPERATOR_NEW
};

struct PointXYZRGBNormalFace : public _PointXYZRGBNormalFace
{
    inline PointXYZRGBNormalFace (const _PointXYZRGBNormalFace &p)
    {
      x = p.x; y = p.y; z = p.z; data[3] = 1.0f;
      normal_x = p.normal_x; normal_y = p.normal_y; normal_z = p.normal_z; data_n[3] = 0.0f;
      curvature = p.curvature;
      rgba = p.rgba;
      face = p.face;
    }

    inline PointXYZRGBNormalFace (float _curvature = 0.f):
        PointXYZRGBNormalFace (0.f, 0.f, 0.f, 0, 0, 0, 0.f, 0.f, 0.f, _curvature, -1) {}

    inline PointXYZRGBNormalFace (float _x, float _y, float _z):
    PointXYZRGBNormalFace (_x, _y, _z, 0, 0, 0) {}

    inline PointXYZRGBNormalFace (std::uint8_t _r, std::uint8_t _g, std::uint8_t _b):
    PointXYZRGBNormalFace (0.f, 0.f, 0.f, _r, _g, _b) {}

    inline PointXYZRGBNormalFace (float _x, float _y, float _z, std::uint8_t _r, std::uint8_t _g, std::uint8_t _b):
    PointXYZRGBNormalFace (_x, _y, _z, _r, _g, _b, 0.f, 0.f, 0.f, 0.f, -1) {}

    inline PointXYZRGBNormalFace (float _x, float _y, float _z, std::uint8_t _r, std::uint8_t _g, std::uint8_t _b,
                            float n_x, float n_y, float n_z, float _curvature, int _face)
    {
      x = _x; y = _y; z = _z;
      data[3] = 1.0f;
      r = _r; g = _g; b = _b;
      a = 255;
      normal_x = n_x; normal_y = n_y; normal_z = n_z;
      data_n[3] = 0.f;
      curvature = _curvature;
      face = _face;
    }
};


POINT_CLOUD_REGISTER_POINT_STRUCT (PointXYZFace,
    (float, x, x)
    (float, y, y)
    (float, z, z)
    (int, face, face)
)

POINT_CLOUD_REGISTER_POINT_STRUCT (PointXYZRGBFace,
    (float, x, x)
    (float, y, y)
    (float, z, z)
    (std::uint32_t, rgba, rgba)
    (int, face, face)
)

POINT_CLOUD_REGISTER_POINT_STRUCT (PointNormalFace,
    (float, x, x)
    (float, y, y)
    (float, z, z)
    (float, normal_x, normal_x)
    (float, normal_y, normal_y)
    (float, normal_z, normal_z)
    (float, curvature, curvature)
    (int, face, face)
)

POINT_CLOUD_REGISTER_POINT_STRUCT (PointXYZRGBNormalFace,
    (float, x, x)
    (float, y, y)
    (float, z, z)
    (float, rgb, rgb)
    (float, normal_x, normal_x)
    (float, normal_y, normal_y)
    (float, normal_z, normal_z)
    (float, curvature, curvature)
    (int, face, face)
)