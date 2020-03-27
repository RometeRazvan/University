package Service;

import Domain.User;
import Repository.UsersRepo;

import java.sql.Connection;

public class ServiceUser implements IServiceUser<User> {

    private UsersRepo ur;

    public ServiceUser(UsersRepo ur) {
        this.ur = ur;
    }

    public ServiceUser() {
        this.ur = new UsersRepo();
    }

    @Override
    public User findByName(String nume) {
        return ur.findByName(nume);
    }

    @Override
    public User findOne(int id) {
        return ur.findOne(id);
    }

    @Override
    public Connection getConnection() {
        return ur.getConnection();
    }
}
