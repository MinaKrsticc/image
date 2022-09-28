//#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "image.h"
#include "io_tools.h"

#define abs(x) x > 0 ? x : - x;

using namespace std;
using namespace igg::io_tools;
namespace igg
{

    Image::Image()
    {
        this->rows_ = 0;
        this->cols_ = 0;
    }

    Image::Image(const int row, const int cols) : data_(row * cols) // (#2) // :data_{} (#3)
    {
        this->cols_ = cols;
        this->rows_ = row;

        // data_ = vector<int>(); // (#4)
        // data_ = {}; // (#5)
        // data_ptr_ = new vector<int>(); // Za dinamicki alociranu memoriju!
        // data_.emplace_back(5);

        for (unsigned int i = 0; i < data_.size(); i++)
        {
            // cout << data_.at(i) << endl;
            cout << data_[i] << endl;
        }

        // for(auto val : data_)
        // {
        //     cout << val << endl;
        // }
    }

    // Image:: ~Image()
    // {
    //     // Za dinamicki alociranu memoriju!

    //     if (this->data_ptr_ != nullptr)
    //     {
    //         delete this->data_ptr_;
    //         this->data_ptr_ = nullptr;
    //     }
    // }

    int Image::cols() const
    {
        return this->cols_;
    }

    int Image::rows() const
    {
        return this->rows_;
    }

    int &Image::at(int row, int col)
    {
        int index = row * this->cols_ + col;
        // return index;
        return this->data_.at(index);
    }

    bool Image::FillFromPgm(const std::string &file_name)
    {
        io_tools::ImageData imgData;
        imgData = io_tools::ReadFromPgm(file_name);

        this->rows_ = imgData.cols;
        this->cols_ = imgData.rows;
        this->max_val_ = imgData.max_val;
        this->data_ = imgData.data;
        cout << this->cols_ << endl;
        // for (int i = 0; i < this->data_.size(); i++)
        // {
        //     cout << this->data_[i] << endl;
        // }

        if (this->cols_ != 0 && this->rows_ != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Image::WriteToPgm(const std::string &file_name)
    {
        io_tools::ImageData imgData;
        imgData.cols = this->rows_;
        imgData.rows = this->cols_;
        imgData.max_val = this->max_val_;
        imgData.data = this->data_;
        bool write = io_tools::WriteToPgm(imgData, file_name);
        if (write == true)
        {
            cout << "upisano" << endl;
        }
        else
        {
            cout << "nije upisano" << endl;
        }
    }

    std::vector<float> Image::ComputeHistogram(int bins)
    {
        float interval = static_cast<float>(255) / static_cast<float>(bins);
        cout << "interval je " << interval << endl;
        float min, max;
        std::vector<float> vec(bins);
        float sum = 0;
        bool fileFromPgm = this->FillFromPgm("../data/lena.ascii.pgm");

        if (fileFromPgm == true)
        {
            int sizePicture = this->data_.size();
            for (int j = 0; j < sizePicture; j++)
            {
                for (int i = 0; i < bins; i++)
                {
                    max = (interval * static_cast<float>(i)) + interval;
                    min = interval * static_cast<float>(i);
                    if (min <= static_cast<float>(this->data_[j]) && static_cast<float>(this->data_[j]) < max)
                    {
                        vec[i] += 1;
                    }
                }
            }
            for (int i = 0; i < bins; i++)
            {
                vec[i] = vec[i] / static_cast<float>(sizePicture);
                sum = sum + vec[i];
            }

            cout << "suma svih elemenata vektora je " << sum << endl;
            return vec;
        }
        return vec;
    }
        
    void Image::DownScale(int scale)
    {
        int smallRow = this->rows_ / scale;
        int smallCols = this->cols_ / scale;
        std::vector<int> vec((smallRow) * (smallCols));
        int prosek;

        for (int im = 0; im < smallRow; im++)
        {
            for (int jm = 0; jm < smallCols; jm++)
            {
                int indexi = im * scale;
                int indexj = jm * scale;
                int sum = 0;
                while (indexi < ((im * scale) + scale))
                {
                    while (indexj < ((jm + 1) * scale))
                    {
                        sum = sum + this->at(indexi, indexj);
                        indexj++;
                    }
                    indexj = jm * scale;
                    indexi++;
                }
                prosek = sum / (scale * scale);
                vec[im * smallCols + jm] = prosek;
            }
        }
        this->rows_ = smallRow;
        this->cols_ = smallCols;
        this->data_ = vec;
    }

    void Image::UpScale(int scale)
    {
        std::vector<int> vec((scale * this->rows_) * (scale * this->cols_));
        int big_cols_ = this->cols_ * scale;

        for (int im = 0; im < this->rows_; im++)
        {
            for (int jm = 0; jm < this->cols_; jm++)
            {
                int indexi = im * scale;
                int indexj = jm * scale;
                while (indexi < ((im * scale) + scale))
                {
                    while (indexj < ((jm + 1) * scale))
                    {
                        vec[indexi * big_cols_ + indexj] = this->at(im, jm);
                        indexj++;
                    }
                    indexj = jm * scale;
                    indexi++;
                }
            }
        }
        this->rows_ = big_cols_;
        this->cols_ = big_cols_;
        this->data_ = vec;
    }

    void Image::Invert()
    {
        int pom;
        // for (int i = 0; i < this->rows_; i++)
        // {
        //     for (int j = 0; j < this->cols_; j++)
        //     {
        //         if (this->data_[i * this->cols_ + j] > 128)
        //         {
        //             pom = this->data_[i * this->cols_ + j] - 128;
        //             this->data_[i * this->cols_ + j] = 128 - pom;
        //         }
        //         else if(this->data_[i * this->cols_ + j] < 128)
        //         {
        //             pom = 128 - this->data_[i * this->cols_ + j];
        //             this->data_[i * this->cols_ + j] = 128 + pom; 
        //         }
        //     }
        // }
        for(auto& pixel : data_)
        {
            if (pixel > 128)
            {
               // pom = pixel - 128;
                pixel = 128 - (pixel - 128);
            }
            else if (pixel < 128)
            {
                //pom = 128 - pixel;
                pixel = 128 + (128 - pixel);
            }
            
        }

        // for (int i=0; i<data_.size(); i++)
        // {
        //     float pixel = data_[i];
        //     pixel = pixel + 1;
        // }

        // for(auto pixel : data_)
        // {
        // pixel = pixel + 1;
        // }

        // for (int i=0; i<data_.size(); i++)
        // {
        //     // 1
        //     data_[i] = data_[i] + 1;
        // }

        
    }

    // bool ReadFromDisk(const std::string& file_name)
    // {
    //     string my_line;
    //     ifstream myfile;
    //     myfile.open(file_name, ios::in);
    //     while (myfile)
    //     {
    //         myfile.getline(file_name, my_line);
    //     }
    // }

    //  void WriteToDisk(const std::string& file_name)
    // {
    //     fstream my_file;
    // 	my_file.open(file_name, ios::out);
    // 	if (!my_file) {
    // 		cout << "File nije kreiran!";
    // 	}
    // 	else {
    // 		cout << "file kreiran uspesno!";
    // 		my_file << "Guru99";
    // 		my_file.close();
    // 	}
    // }
}