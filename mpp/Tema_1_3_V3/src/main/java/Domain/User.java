package Domain;

import java.util.Objects;

public class User extends Entity {

    private String nume, password;

    public String getNume() {
        return nume;
    }

    public String getPassword() {
        return password;
    }

    public User(int id, String nume, String password) {
        super(id);
        this.nume = nume;
        this.password = password;
    }

    public User(String nume, String password) {
        super(0);
        this.nume = nume;
        this.password = password;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof User)) return false;
        User user = (User) o;
        return Objects.equals(getNume(), user.getNume()) &&
                Objects.equals(getPassword(), user.getPassword());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getNume(), getPassword());
    }
}
