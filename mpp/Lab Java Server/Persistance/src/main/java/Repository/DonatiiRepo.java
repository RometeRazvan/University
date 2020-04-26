package Repository;


import IRepository.IDonatiiRepo;
import Models.Donatie;
import Tools.DBAdd;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.Serializable;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;

public class DonatiiRepo implements IDonatiiRepo {

    private Connection conn;
    private static final Logger logger = LogManager.getLogger();

    public DonatiiRepo() {conn = new DBAdd().getNewConnection();}

    public Connection getConneection() {return conn;}

    @Override
    public Donatie findByNameAddressPhone(String nume, String address, String phone) {
        try {
            if(conn.isClosed())
                return null;
        }
        catch(Exception e) {
            logger.error(e);
            return null;
        }

        String stmt = "Select * from Donatii where nume is ? and adresa is ? and nrTel is ?";

        try(PreparedStatement ppstmt = conn.prepareStatement(stmt)) {
            ppstmt.setString(1, nume);
            ppstmt.setString(2, address);
            ppstmt.setString(3, phone);
            ResultSet rs = ppstmt.executeQuery();
            if(rs.next()) return new Donatie(rs.getInt("id"), rs.getString("nume"), rs.getString("adresa"), rs.getString("nrTel"), rs.getInt("suma"));
            else logger.error("Nu s-a gasit donatorul cu datele " + nume + address + phone);
        }
        catch (Exception e) {
            logger.error(e);
        }

        return null;
    }

    @Override
    public Donatie findByName(String nume) {
        try {
            if(conn.isClosed())
                return null;
        }
        catch(Exception e) {
            logger.error(e);
            return null;
        }

        String stmt = "Select * from Donatii where nume is ?";

        try(PreparedStatement ppstmt = conn.prepareStatement(stmt)) {
            ppstmt.setString(1, nume);
            ResultSet rs = ppstmt.executeQuery();
            if(rs.next()) return new Donatie(rs.getInt("id"), rs.getString("nume"), rs.getString("adresa"), rs.getString("nrTel"), rs.getInt("suma"));
            else logger.error("Nu s-a gasit donatorul cu numele " + nume);
        }
        catch (Exception e) {
            logger.error(e);
        }

        return null;
    }

    @Override
    public Iterable<Donatie> searchByPartialName(String nume) {
        try {
            if(conn.isClosed())
                return null;
        }
        catch(Exception e) {
            logger.error(e);
            return null;
        }

        try {
            String stmt = "Select * from Donatii where charindex(?, nume) > 0 ";

            PreparedStatement ppstmt = conn.prepareStatement(stmt);
            ppstmt.setString(1, nume);

            ResultSet rs = ppstmt.executeQuery();

            ArrayList<Donatie> al = new ArrayList<>();

            while (rs.next()) {
                Donatie donatie = new Donatie(rs.getString("nume"), rs.getString("adresa"), rs.getString("nrTel"), rs.getInt("suma"));
                al.add(donatie);
            }

            return al;
        }
        catch (Exception e) {
            logger.error(e);
        }

        return null;
    }

    @Override
    public Donatie findOne(int id) {
        try {
            if(conn.isClosed())
                return null;
        }
        catch(Exception e) {
            logger.error(e);
            return null;
        }

        String stmt = "Select * from Donatii where id is ?";

        try(PreparedStatement ppstmt = conn.prepareStatement(stmt)) {
            ppstmt.setInt(1, id);
            ResultSet rs = ppstmt.executeQuery();
            if(rs.next()) return new Donatie(rs.getInt("id"), rs.getString("nume"), rs.getString("adresa"), rs.getString("nrTel"), rs.getInt("suma"));
            else logger.error("Nu s-a gasit donatorul cu id-ul " + id);
        }
        catch(Exception e) {
            logger.error(e);
        }

        return null;
    }

    @Override
    public Donatie save(Donatie entity) {
        try {
            if(conn.isClosed())
                return null;
        }
        catch(Exception e) {
            logger.error(e);
            return null;
        }

        String stmt = "Insert into Donatii(nume, adresa, nrtel, suma) Values(?,?,?,?)";

        if(findByNameAddressPhone(entity.getNume(), entity.getAdresa(), entity.getNrTel()) == null) {
            try(PreparedStatement ppstmt = conn.prepareStatement(stmt)) {
                ppstmt.setString(1, entity.getNume());
                ppstmt.setString(2, entity.getAdresa());
                ppstmt.setString(3, entity.getNrTel());
                ppstmt.setInt(4, entity.getSuma());
                ppstmt.executeUpdate();
                return findByNameAddressPhone(entity.getNume(), entity.getAdresa(), entity.getNrTel());
            }
            catch (Exception e) {
                logger.error(e);
            }
        }

        return null;
    }

    @Override
    public void clear() {
        try {
            if(conn.isClosed())
                return;
        }
        catch(Exception e) {
            logger.error(e);
            return;
        }

        String stmt = "Delete from Donatii";

        try(PreparedStatement ppstmt = conn.prepareStatement(stmt)) {
            ppstmt.executeUpdate();
        }
        catch (Exception e) {
            logger.error(e);
        }
    }
}
