//#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "image.h"
#include "io_tools.h"

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
        int p = 0;
        float mat[scale][scale];
        float pom = 0;
        int step = 0;
        std::vector<float> vec(scale * scale);
        if (this->cols_ % scale == 0 && this->rows_ % scale == 0 && this->cols_ == this->rows_)
        {
            while (step <= this->rows_ - scale )
            {
                for (int j = step; j < scale ; j++)
                {
                    for (int k = 0; k < scale ; k++)
                    {
                        pom = pom + this->at(j,k); //treba da se nesto uradi , da se
                    }
                }
                int prosek = pom / (scale * scale);
                vec[p] = prosek;
                p++;
                step = step + scale;
            }
            // napraviti da se pomera i duz reda
        }
    }
    void Image::UpScale(int scale)
    {

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