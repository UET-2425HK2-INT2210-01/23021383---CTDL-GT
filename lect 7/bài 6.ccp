// hàm đếm tổng chữ số
int sum(int n)
{
	if (n < 10) return n; // điều kiện dừng khi còn 1 số thì return về số đó
	else {
		return (n % 10) + sum(n / 10); // đệ quy với phần dư của n / 10 (số cuối)
		                               // + sum(n / 10) n - 1 số đầu
	}
}
