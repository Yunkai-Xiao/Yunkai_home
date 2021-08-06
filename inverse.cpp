#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Matrix{
  vector<float> datas;
  int width; 
  int height;

  void _inverse(int w, int h, int tileSize);
  public:
  Matrix(int w, int h);
  float& at(int r, int c);
  void inverse();
  void print();
};

void Matrix::print() {
  for (int i = 0 ; i < width; i++) {
    for (int j = 0; j < width; j++) {
      cout << setw(10) << at(i, j); 
    }
    cout << endl;
  }
}
Matrix::Matrix(int w, int h) {
  width = w;
  height = h;
  for (int i = 0 ; i < w; i++) {
    for (int j = 0; j < h; j++) {
      float s;
      cin >> s;
      datas.push_back(s);
    }
  }
}

float& Matrix::at(int r, int c) {
  return datas.at(c * height + r);
}

void Matrix::_inverse(int r, int c, int tileSize) {
  
  if (tileSize == 1) {
    float& d = this->at(r, c);
    d = 1 / d;
  } else {
    int tile1 = tileSize / 2;
    int tile2 = tileSize - tile1;
    _inverse(r, c, tile1);
    _inverse(r + tile1, c + tile1, tile2);
    
    vector<float> tmp;
    for (int i = 0 ; i < tile2; i++) {
      for (int j = 0; j < tile1; j++) {
        float lst = 0;
        for (int k = 0; k < tile2; k++) {
          lst +=  -1 * this->at(r + tile1 + i, c + tile1 + k) *  this->at(r + tile1 + k, c + j);
        }
        tmp.push_back(lst);
      }
    }

    for (int i = 0 ; i < tile2; i++) {
      for (int j = 0; j < tile1; j++) {
        this->at(r + tile1 + i, c + j) = tmp[i * tile1 + j];
      }
    }
    vector<float> tmp1;
    for (int i = 0 ; i < tile2; i++) {
      for (int j = 0; j < tile1; j++) {
        float lst = 0;
        for (int k = 0; k < tile1; k++) {
          lst += this->at(r + tile1 + i, c + k) *  this->at(r + k, c + j);
        }
        tmp1.push_back(lst);
      }
    }

    for (int i = 0 ; i < tile2; i++) {
      for (int j = 0; j < tile1; j++) {
        this->at(r + tile1 + i, c + j) = tmp1[i * tile1 + j];
      }
    }
  }
}

void Matrix::inverse() {
  _inverse(0, 0, width);
}

int main() {
  Matrix* myMatrix = new Matrix(6, 6);
  cout << "Original: " << endl;
  myMatrix -> print();
  myMatrix -> inverse();

  cout << "Inversed: " << endl;
  myMatrix -> print();
  return 0;
}