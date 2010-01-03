#ifndef DWALK_H
#define DWALK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <boost/algorithm/string.hpp>

typedef std::vector<double> Array;
typedef std::vector<Array> Matrix;
typedef std::vector<unsigned int> LabelArray;
typedef std::vector<LabelArray> LabelMatrix;

class Dwalk
{
  int a, b;
  unsigned int nodesz, labelsz, lnodesz, unodesz;
  Matrix mat;
  LabelMatrix lmat, lcmat;

  void normalize(Matrix& mat);
public:
  Dwalk()
  { }

  void show_info();
  LabelArray get_complement_labeled_nodes (const unsigned int label_id);
  LabelArray get_labeled_nodes (const unsigned int label_id);
  void load(
      const char* graph_fn,
      const char* label_fn,
      const bool symm);
  void calc_alpha(
      std::vector<Matrix>& alpha_v,
      const Matrix& mat,
      const LabelMatrix& lmat,
      const LabelMatrix& lcmat,
      const unsigned int L,
      const unsigned int labelsz,
      const unsigned int nodesz);
  void calc_beta(
      std::vector<Matrix>& beta_v,
      const Matrix& mat,
      const LabelMatrix& lmat,
      const LabelMatrix& lcmat,
      const unsigned int L,
      const unsigned int labelsz,
      const unsigned int nodesz);
  void show_predict(const std::vector<unsigned int>& predict);
  void show_alphabeta(
      const unsigned int t,
      const std::string label,
      const Matrix& mat);
  void show_lmat(const LabelMatrix& lmat);
  void show_betweenness(const Matrix& mat);
  void show_mat(const Matrix& mat);
  void go(const unsigned int L,
          const std::string& pref_fn,
          const bool map_predict);
};

#endif
