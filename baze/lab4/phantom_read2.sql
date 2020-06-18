create procedure phantom_read2
As
	Begin
		Begin Transaction;
			WAITFOR DELAY '00:00:03';
			Declare @idClient int;
			Select @idClient=(Max(idClient)+1) From Client;
			Insert into Client(idClient , nume , telefon) values(@idClient , 'Alexandru','0785678761');
		Commit Transaction;
	End

phantom_read2