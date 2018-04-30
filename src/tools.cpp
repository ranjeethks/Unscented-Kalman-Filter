#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  
  VectorXd rmse(4);
  rmse << 0,0,0,0;
  
  if (estimations.size() != ground_truth.size() or estimations.size() == 0) {
	  cout << "No estimates found!" << endl;
	  return rmse;
  }
  
  for (unsigned int i = 0; i < estimations.size(); ++i) {
	  VectorXd estimate = estimations[i];
	  VectorXd ground_t = ground_truth[i];
	  VectorXd error = estimate - ground_t;
	  error = error.array() * error.array();
	  rmse += error;
  }
  
  //calculate the mean
  rmse = rmse/estimations.size();
  
  //calculate the squared root
  rmse = rmse.array().sqrt();
  
  return rmse;
}