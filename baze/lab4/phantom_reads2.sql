create procedure phantom_reads2
as
	begin
		begin transaction
			select * from Client where idClient between 1 and 100;
			waitfor delay '00:00:06';
			select * from Client where idClient between 1 and 100;
		commit transaction
	end


