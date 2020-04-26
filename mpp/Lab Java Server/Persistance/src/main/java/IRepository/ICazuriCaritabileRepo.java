package IRepository;

import Models.Caritate;

public interface ICazuriCaritabileRepo {

    Caritate findByName(String nume);

    Iterable<Caritate> findAll();

    void addSuma(String nume, Integer suma);

    Caritate findOne(int id);

    Caritate save(Caritate entity);

    void clear();
}
