﻿#include"Fake_name.h"
Fullname Fakename::next() {
	Fullname temp;
	temp._firstName = firstName[rand() % 132];
	temp._middleName = middleName[rand() % 5];
	temp._lastName = lastName[rand() % 850];
	return temp;
}

string Fakename::firstName[132] = { "An","Au Duong","Bach","Banh","Bien","Bui","Cu","Cai","Cam","Cao","Cap","Che","Chu"
,"Chuc","Chung","Chu","Chuong","Cung","Diep","Doan","Du","Du","Duong","Dam","Dan"
,"Dao","Dang","Dien","Dinh","Doan","Do","Dong","Dong","Doi","Duong","Gia","Gian","Giang","Giang","Giap"
,"Ha", "Ha", "Hinh", "Hoa","Hoang", "Hoang Phu", "Ho", "Hong", "Hung", "Hua", "Huong", "Kha",
"Khang", "Khau", "Khuat", "Khuc", "Khuong", "Kieu", "Kim", "Ksor", "La", "Lai", "Lam", "Lam", "Le", "Lien", "Lo", "Loc", "Luc", "Lu",
"Lu", "Luong" ,"Luu" ,"Ly","Ma", "Mac", "Mai", "Man", "Mau", "Mieu", "Nghiem", "Ngo", "Nguy", "Nguyen", "Nguyen Phuoc toc"
,"Nham", "Nhu", "Ninh", "Nong", "Ong", "Pham", "Phan", "Phi", "Pho", "Phung"
,"Phuong", "Quach", "Quan", "Que", "Sam", "Su", "Ta", "Tang", "Thach",
"Thai", "Thang", "Than", "Thi", "Thieu", "Thieu", "Thoi", "Tiet", "Tieu",
"To", "Ton", "Ton Nu", "Tong", "Trang", "Tran", "Tri", "Trieu", "Trinh", "Trinh",
"Trung", "Tu", "Tuong", "Uong Van", "Vi", "Vien", "Vong", "Vu", "Vuong" };
string Fakename::middleName[5] = { "Van","Huu","Thi","Duc","Anh" };
string Fakename::lastName[850] = { "Ai","Am" ,"An"
,"An","Anh","Anh","An","An","An","Ap","At","Au","Au","Ba","Ba","Ba","Bac","Bach","Bach","Bai"
,"Bai","Ban","Ban","Bang","Bang","Bao","Bao","Bao","Bat","Bau","Bac"
,"Bang","Bat","Ban","Bat","Ben","Ben","Bi","Bich","Bien","Bien","Bien","Bieu","Binh","Binh"
,"Bo","Bo","Bo","Boc","Boc","Boi","Boi","Boi","Boi","Bon","Bon","Bon","Bong","Bong","Bong","Bot","Bui","Buong","But","Bung","Buu","Ca"
,"Cai","Cam","Can","Canh","Canh","Can","Cao","Cao","Cat","Can","Cam","Cam","Can","Can","Can","Cat","Cau"
,"Cau","Chanh","Chanh","Cham","Cham","Chan","Chan","Chan","Chap","Chat","Chau","Che","Chi","Chi	","Chi"
,"Chiem","Chiem","Chien","Chieu","Chieu","Chinh","Chinh","Chinh","Chinh"
,"Chu","Chu","Chu","Chua","Chuc","Chung","Chung","Chuyen","Chuyen","Chu","Chu","Chuc"
,"Chuoc","Chuong","Chuong","Co","Con","Con","Cong","Cong","Co","Cu","Cu","Cuc","Cung","Cung"
,"Cu","Cu","Cu","Cu","Cu","Cuong","Cuong","Cuu","Cuu","Cuu","Danh","Dao","Dan"
,"Dan","Dan","Dat","Di","Di","Dich","Diem","Diem","Diem","Diep","Diep","Dieu","Dinh","Dinh","Do	"
,"Doan","Doanh","Du","Du","Du","Duat","Duc","Due","Dung","Dung","Dung"
,"Duy","Duyen","Duyet","Du","Du","Duc","Duoc","Duong","Duong","Dac","Dai","Dai","Dam"
,"Dam","Dam","Dam","Dan","Dan","Dan","Dan","Dao","Dang","Dang"
,"Dang","Dao	","Dao	","Dao	","Dat	","Dac	","Dang	","Dang	","Dang	","Dau	","Dau	","De	","De","Diem"
,"Dien","Diep	","Dieu	","Dieu	","Dinh	","Dinh	","Dinh	","Dinh	","Dinh	","Dinh	","Doa	","Doai	","Doai	"
,"Doan","Doan	","Do	","Do	","Do	","Doc	","Doi	","Don	","Dong	","Dong	","Dong	","Doi	"
,"Don","Du	","Duc	","Duoc	","Duong	","Duong	","Em	","Gia	","Gia	","Gia	","Giac	","Giai	","Giai	","Giam	","Gian	"
,"Gian","Giang	","Giang	","Giao	","Giao	","Giap	","Giau	","Gioi	","Giu	","Ha	","Ha	","Hac	","Hach	","Hai	","Hai	","Hai	","Ham	","Han	","Han	","Han	","Han	","Hang	","Hanh	","Hanh	","Hanh	","Hao	"
,"Hao","Hao	","Hap	","Hat	","Hang	","Han	","Hau	","Hien	","Hien	","Hien	","Hiep	","Hiet	","Hieu	","Hieu	","Hieu	"
,"Hinh","Hoa	","Hoa	","Hoa	","Hoach	","Hoai	","Hoan	","Hoan	","Hoang	","Hoanh	"
,"Hoanh","Hoc	","Hoat	","Ho	","Ho	","Ho	","Hoi	","Hoi	","Hoi	","Hong	","Hop	","Huan	","Huan	"
,"Hue","Hue	","Hung	","Huy	","Huyen	","Huyen	","Huyen	","Huyen	","Huynh	","Huynh	","Hua	","Hung	"
,"Huong","Huong	","Huong	","Huong	","Huu	","Huu	","Huu	","Hy	","Hy	","Ich	","Keo	","Ke	"
,"Ket","Kha	","Kha	","Kha	","Khai	","Khai	","Khai	","Kham	","Khan	","Khang	","Khang	","Khang	"
,"Khanh","Khanh	","Khao	","Khac	","Kham	","Khan	","Khap	","Khau	","Khe	","Khiem	","Khiet	","Khieu	"
,"Khinh","Khoa	","Khoa	","Khoa	","Khoach	","Khoai	","Khoan	","Khoan	","Khoat	"
,"Khoi","Khon	","Khong	","Khu	","Khuc	","Khue	","Khuong	","Khuyen	","Khuyet	","Khuynh	"
,"Khuong","Khuu	","Kiem	","Kiem	","Kiem	","Kien	","Kien	","Kiet	","Kieu	","Kim	","Kinh	","Kinh	","Kinh	","Ky	","Ky	","Ky	","La	"
,"Lac","Lai	","Lai	","Lai	","Lam	","Lam	","Lan	","Lang	","Lang	","Lanh	","Lanh	","Lanh	","Lap	","Lang	","Lam	"
,"Lan","Lap	","Lau	","Le	","Le	","Le	","Lich	","Liem	","Lien	","Lien	","Lieu	","Lieu	","Lieu	","Linh	","Loan	"
,"Long","Lo	","Loc	","Loi	","Loi	","Loi	","Lua	","Luan	","Luan	","Luat	","Luc	","Luy	","Luyen	","Luyen	","Lu	","Lu	","Luc	","Luoc	","Luong	","Luong	","Luu	","Luu	","Ly	","Ly	","Mai	","Mai	","Man	","Manh	","Mao	","Mao	"
,"Man","Mau	","Mau	","May	","Mich	","Minh	","Mit	","Moc	","Muu	","Nam	","Nam	","Nang	","Nga	","Ngac	","Ngai	","Ngan	","Ngan	","Nghe	"
,"Nghe","Nghi	","Nghi	","Nghia	 ","Nghiem	","Nghien	","Nghiep	","Nghinh	","Ngo	","Ngoa	","Ngoan	","Ngoan	"
,"Ngoc","Ngo	","Ngo	","Ngon	","Ngu	","Ngu	","Ngung	","Nguyen	","Nguyen","Nguyet	","Ngu	","Ngu	","Nha	 ","Nhac	","Nham	","Nham	","Nhan	","Nhan	","Nhan	","Nham	","Nhan	","Nhan	","Nhat	","Nhat	","Nhi	"
,"Nhi","Nhiem	","Nhien	","Nhiep	","Nhieu	","Nhieu	","Nho	","Nhu	","Nhuan	","Nhue	","Nhung	","Nhu	"
,"Nhu","Nhuong	","Niem	","Niem	","Nien	","Ninh	","Noi	","Nong	","Nu	","Nuong	","Oai	","Oanh	","Oanh	","On	","Pha	","Phach	"
,"Phai","Pham	","Pham	","Phan	","Phan	","Phat	","Phan	","Phe	","Phi	","Phien	","Phien	","Phiet	","Phieu	","Pho	","Phong	","Phong	","Phong	"
,"Pho","Pho	","Phon	","Phu	","Phu	","Phu	","Phu	","Phuc	","Phuc	","Phung	","Phung	","Phuc	","Phuoc	","Phuong","Phuong	"
,"Qua","Qua	","Qua	","Quan	","Quan	","Quan	","Quang	","Quang	","Quan	","Quan	","Que	"
,"Quoc","Quit	","Quy	","Quy	","Quy	","Quyen	","Quyen	","Quyen	","Quyet	","Quynh	","Quynh	","Sach	","Sam	"
,"San","Sang	","Sang	","Sanh	","Sanh	","Sao	","Sat	","Sac	","Sam	","Sinh	","Si	","Sieu	","Sinh	","Sinh	","Soan	","Song	","So	","Son	","Sung	"
,"Su","Su	","Su	","Suong	","Suu	","Ta	","Ta	","Tac	","Tai	","Tac	","Tam	","Tam	"
,"Tao","Tang	","Tam	","Tam	","Tan	","Tan	","Tan	","Tap	","Tat	","Tay	","Te	","Thach	","Thai	"
,"Thang","Thanh	","Thanh	","Thanh	","Thao	","Thao	","Thang	","Thang	","Than	","Than	","Thap	","Thau	","The	"
,"The","Thi	","Thi	","Thi	","Thi	","Thich	","Thien	","Thien	","Thiep	","Thiet	","Thinh	","Thinh	"
,"Tho","Thoa	","Thoa	","Thoai	","Thoan	","Thoi	","Thong	","Thong	","Thoi	","Thu	","Thu	","Thu	","Thuan	"
,"Thuan","Thuan","Thuat","Thuc	","Thuc	","Thuy	","Thuy	","Thuy	","Thuy	","Thuyen	","Thuyet	","Thu	","Thu	","Thua	","Thuc	"
,"Thuc","Thuoc","Thuoc","Thuong","Thuong","Thuong","Thuong","Thy","Tich","Tiem","Tiem","Tien","Tien","Tien","Tien","Tiep","Tiet","Tieu","Tieu","Tin	"
,"Tinh","Tinh","Tinh","Tinh","Tinh","Toa","Toa","Toai","Toan","Toan","Toan","Toan","Toat","Tong"
,"To","To","To","To","Ton","Ton","Tong","Tot","Tra","Trac","Trac","Trach","Trai","Trang"
,"Trang","Trang","Trang","Trat","Trac","Tram","Tram","Tran","Tran","Tran","Tri"
,"Tri","Tri	","Tri","Trich","Triem","Trien","Triet","Trieu","Trieu","Trinh","Trinh","Trinh"
,"Trong","Tro","Tru","Truat","Truc","Trung","Truyen","Tru","Tru","Truc","Trung","Trung","Truoc"
,"Truong","Truong","Truong","Tu","Tuan","Tuan","Tuan","Tuc","Tue","Tue","Tung","Tung","Tung"
,"Tuy","Tuy","Tuy","Tuyen","Tuyen","Tuyen","Tuyen","Tuyet","Tu","Tu","Tu","Tu"
,"Tuoc","Tuong","Tuong","Tuong","Tuu","Tuu","Ty","Ty","Ty","Uan","Uy","Uy","Uyen","Uyen","Uong","Uu","Vang"
,"Van","Van","Ve","Vi","Vien","Vien","Vien","Viet","Vinh","Vinh","Vinh","Vo","Vong","Vu","Vui","Vy"
,"Vuong","Vuong","Xa","Xa","Xoai","Xuan","Xuyen","Xuyen","Xuong","Xuong","Yem","Yem","Yen","Yen" };

