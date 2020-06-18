alter procedure non_repetable1
	as
		begin
			begin Transaction;
				Update Client set nume = 'Florin' where idClient = 1;
				waitfor delay '00:00:08';
			rollback Transaction;
		end

non_repetable1;
