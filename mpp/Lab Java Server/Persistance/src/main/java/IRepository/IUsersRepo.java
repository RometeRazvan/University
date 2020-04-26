package IRepository;


import Models.User;

public interface IUsersRepo {

    User findByName(String nume);

    User findOne(int id);

    User save(User entity);

    void clear();

}
