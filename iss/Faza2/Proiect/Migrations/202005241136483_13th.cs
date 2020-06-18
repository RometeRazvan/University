namespace Faza2.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class _13th : DbMigration
    {
        public override void Up()
        {
            DropPrimaryKey("dbo.Loc");
            DropPrimaryKey("dbo.Rezervare");
            DropPrimaryKey("dbo.Spectator");
            AlterColumn("dbo.Loc", "id", c => c.Guid(nullable: false));
            AlterColumn("dbo.Rezervare", "id", c => c.Guid(nullable: false));
            AlterColumn("dbo.Spectator", "id", c => c.Guid(nullable: false));
            AddPrimaryKey("dbo.Loc", "id");
            AddPrimaryKey("dbo.Rezervare", "id");
            AddPrimaryKey("dbo.Spectator", "id");
        }
        
        public override void Down()
        {
            DropPrimaryKey("dbo.Spectator");
            DropPrimaryKey("dbo.Rezervare");
            DropPrimaryKey("dbo.Loc");
            AlterColumn("dbo.Spectator", "id", c => c.Guid(nullable: false, identity: true));
            AlterColumn("dbo.Rezervare", "id", c => c.Guid(nullable: false, identity: true));
            AlterColumn("dbo.Loc", "id", c => c.Guid(nullable: false, identity: true));
            AddPrimaryKey("dbo.Spectator", "id");
            AddPrimaryKey("dbo.Rezervare", "id");
            AddPrimaryKey("dbo.Loc", "id");
        }
    }
}
