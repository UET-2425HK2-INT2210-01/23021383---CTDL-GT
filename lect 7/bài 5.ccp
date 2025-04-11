// hàm đếm chữ số
int count(int n)
{
	if (n < 10) return 1; // điều kiện dừng khi còn 1 chữ số thì return 1
	else {
		return 1 + count(n / 10); // đệ quy với 1 + phần nguyên của n / 10 (bỏ đi 1 số cuối)
	}
}
