/*
 * 2.06: Tìm kiếm Nhị phân: Tìm trong mảng học sinh
 *
 * Hãy hoàn thành hàm BSearch(Hocsinh [], int, Hocsinh) để tìm học sinh có họ
 * đệm, tên, ngày, tháng, năm sinh trong một mảng học sinh đã được sắp xếp theo
 * thứ tự tăng dần của tên, nếu tên trùng nhau thì xét thứ tự Họ đệm tăng dần.
 * Nếu tên và họ đệm trùng nhau, thì xét tuổi tăng dần. Một người có tuổi nhỏ
 * hơn nếu có ngày sinh (bao gồm ngày, tháng, năm) lớn hơn. Thứ tự của tên, họ
 * đệm cũng chính là thứ tự chuỗi theo bảng mã ASCII. Nếu tìm thấy, trả về số
 * lần duyệt qua các khóa; nếu không tìm thấy, trả về số 0.
 *
 * Cấm: define, include.
 */

/*
 * BẮT ĐẦU MẪU
 */
#include <iostream>

#define MAX 10000

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

int BSearch(Hocsinh [], int, Hocsinh);

int main()
{
    Hocsinh ds[MAX], hs;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        ds[i] = hs;
    }
    InputElement(hs);
    cout << BSearch(ds, n, hs) << endl;
    return 0;
}
/*
 * KẾT THÚC MẪU
 */

#pragma GCC optimize("O3")

bool
Less(const Hocsinh &A, const Hocsinh &B)
{
	if (A.Ten != B.Ten)
		return A.Ten < B.Ten;
	if (A.Hodem != B.Hodem)
		return A.Hodem < B.Hodem;
	if (A.Nam != B.Nam)
		return A.Nam > B.Nam;
	if (A.Thang != B.Thang)
		return A.Thang > B.Thang;
	return A.Ngay > B.Ngay;
}

bool
IsEqual(const Hocsinh &A, const Hocsinh &B)
{
	if (A.Ten != B.Ten)
		return false;
	if (A.Hodem != B.Hodem)
		return false;
	if (A.Nam != B.Nam)
		return false;
	if (A.Thang != B.Thang)
		return false;
	if (A.Ngay != B.Ngay)
		return false;
	return true;
}

int
BSearch(Hocsinh Array[], int Size, Hocsinh x)
{
	int Left = 0, Right = Size - 1, Mid;
	int i = 0;

	while (Left <= Right)
	{
		i++;
		Mid = Left + (Right - Left) / 2;
		if (IsEqual(x, Array[Mid]))
			return i;
		if (Less(x, Array[Mid]))
			Right = Mid - 1;
		else
			Left = Mid + 1;
	}
	return 0;
}
