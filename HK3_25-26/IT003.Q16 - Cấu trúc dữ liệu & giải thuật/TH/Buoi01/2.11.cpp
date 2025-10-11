/*
 * 2.11: Sắp xếp danh sách học sinh theo thứ tự giảm dần.
 *
 * Hãy hoàn thành hàm Sort(vector &) để sắp xếp danh sách học sinh theo thứ tự
 * tăng dần của tên. Thứ tự của tên cũng chính là thứ tự chuỗi theo bảng mã
 * ASCII. Trường hợp các học sinh trùng tên, thì học sinh nào xuất hiện trước
 * trong danh sách trước khi sắp xếp cũng sẽ xuất hiện trước trong danh sách
 * sau khi sắp xếp.
 *
 * Cấm: define, include.
 */

/*
 * BẮT ĐẦU MẪU
 */
#include <iostream>
#include <vector>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

void Output(vector<Hocsinh> ls) {
    for (int i = 0; i < ls.size(); i++) {
        OutputElement(ls[i]);
    }
}

void Input(vector<Hocsinh> &ls) {
    int n;
    cin >> n;
    Hocsinh hs;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        ls.push_back(hs);
    }
}

void Sort(vector<Hocsinh> &ls);

int main()
{
    vector<Hocsinh> ls;
    Input(ls);
    Sort(ls);
    Output(ls);
    return 0;
}
/*
 * KẾT THÚC MẪU
 */

#pragma GCC optimize("O3")

bool
Less(const Hocsinh& A, const Hocsinh& B)
{
	return (A.Ten < B.Ten);
}

void
Sort(vector<Hocsinh> &A)
{
	for (int i = 1; i < A.size(); i++)
	{
		int k = i - 1;
		Hocsinh e = A[i];
		while (k >= 0 && Less(e, A[k]))
		{
			A[k + 1] = A[k];
			k--;
		}
		A[k + 1] = e;
	}
}
