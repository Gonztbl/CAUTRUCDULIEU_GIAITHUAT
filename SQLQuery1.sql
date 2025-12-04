create database QLBANHANG
go 
use QLBANHANG
GO
CREATE TABLE KHACHHANG(
 MaKh nvarchar(5) not null primary key ,
 TenKh nvarchar(30) not null,
 Diachi nvarchar(300) not null,
 Dienthoai varchar(10) not null,

)
create table Vattu(
MaVt nvarchar(5) not null primary key,
TenVt nvarchar(30) not null,
Giamua money,
Soluong int,
)
go
create table HoaDon(
MaHD nvarchar(10) not null primary key,
ngay datetime not null,
MaKh nvarchar(5) not null,
tongtien money null,
)
go
create table CHITIETHOADON(
 MaHD nvarchar(10) not null,
 MaVt nvarchar(5) not null,
 Soluong int,
 Giaban money,
 foreign key (MaHD) references HOADON(MaHD),
 foreign key (MaVt) references Vattu(MaVt),
)
go
--Nhập thông tin khách hàng 
drop table KHACHHANG
INSERT INTO KHACHHANG(MaKh,TenKh,Diachi,Dienthoai) VALUES
('1','Long',N'Hà Nội','001'),
('2','Mai',N'Hải Phòng','002'),
('3',N'Hiền',N'Nam Định','003'),
('4',N'Hoàng',N'Thanh Hóa','004'),
('5',N'Tú',N'Thái Bình','005'),
('6',N'Khải',N'Kim Liên','006'),
('7',N'Linh',N'Hà Nội','007');
--Nhập thông tin vật tư 
insert into Vattu(MaVt,TenVt,Giamua,Soluong) values
('01',N'Bút','50000','66'),
('02',N'Laptop','6000','6666'),
('03',N'Balo','454211','5004'),
('04',N'Thước','444444','44'),
('05',N'Lược','4447645','30'),
('06',N'Mì','575247','1'),
('07',N'Chip','13','2');
go
-- Truy vấn dữ liệu
select MaKh,TenKh,Diachi[Địa Chỉ],Dienthoai[Điện Thoại]
from KHACHHANG
where Diachi=N'Hà Nội'

