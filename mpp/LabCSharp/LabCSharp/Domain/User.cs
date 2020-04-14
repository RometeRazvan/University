using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;

namespace LabCSharp.Domain
{
    public class User
    {

        public string Username { get; }
        public string Password { get; }
        
        public int Id { get; }
        
        public User(string username, string password)
        {
            Username = username;
            Password = password;
        }

        public User(string username, string password, int id)
        {
            Username = username;
            Password = password;
            Id = id;
        }

        public override string ToString()
        {
            return $"{nameof(Username)} : {Username}, {nameof(Password)} : {Password}";
        }

        public bool EqualData(object obj)
        {
            if (GetType() != obj.GetType()) return false;
            return EqualString((User) obj);
        }

        public bool EqualString(User user)
        {
            return Username.Equals(user.Username) && Password.Equals(user.Password);
        }
    }
}