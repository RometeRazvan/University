namespace Faza2.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class _11th : DbMigration
    {
        public override void Up()
        {
            CreateIndex("dbo.Rezervare", "piesaId");
            CreateIndex("dbo.Rezervare", "spectatorId");
            CreateIndex("dbo.Rezervare", "locId");
            AddForeignKey("dbo.Rezervare", "locId", "dbo.Loc", "id", cascadeDelete: true);
            AddForeignKey("dbo.Rezervare", "piesaId", "dbo.Piesa", "id", cascadeDelete: true);
            AddForeignKey("dbo.Rezervare", "spectatorId", "dbo.Spectator", "id", cascadeDelete: true);
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Rezervare", "spectatorId", "dbo.Spectator");
            DropForeignKey("dbo.Rezervare", "piesaId", "dbo.Piesa");
            DropForeignKey("dbo.Rezervare", "locId", "dbo.Loc");
            DropIndex("dbo.Rezervare", new[] { "locId" });
            DropIndex("dbo.Rezervare", new[] { "spectatorId" });
            DropIndex("dbo.Rezervare", new[] { "piesaId" });
        }
    }
}
