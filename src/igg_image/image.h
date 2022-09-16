#pragma once

#include <vector>
namespace igg {

class Image {
 public:
 Image();
 Image(int row, int cols);
 int rows() const;
 int cols() const;
 int& at(int row, int col);
 bool FillFromPgm(const std::string& file_name);
 void WriteToPgm(const std::string& file_name);
 bool ReadFromDisk(const std::string& file_name);
 void WriteToDisk(const std::string& file_name);
 std::vector<float> ComputeHistogram(int bins);
 void DownScale(int scale);
 void UpScale(int scale);
 //Image operator=(const Image& img);

// Image operator+(const Image& img);
  ///////////////////// Create the public interface here ///////////////////////
 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
  //std::vector<int>* data_ptr_;
};

}  // namespace igg
