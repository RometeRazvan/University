namespace Faza2.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class _10th : DbMigration
    {
        public override void Up()
        {
            DropForeignKey("dbo.Rezervare", "locId", "dbo.Loc");
            DropForeignKey("dbo.Rezervare", "piesaId", "dbo.Piesa");
            DropForeignKey("dbo.Rezervare", "spectatorId", "dbo.Spectator");
            DropIndex("dbo.Rezervare", new[] { "piesaId" });
            DropIndex("dbo.Rezervare", new[] { "spectatorId" });
            DropIndex("dbo.Rezervare", new[] { "locId" });
        }
        
        public override void Down()
        {
            CreateIndex("dbo.Rezervare", "locId");
            CreateIndex("dbo.Rezervare", "spectatorId");
            CreateIndex("dbo.Rezervare", "piesaId");
            AddForeignKey("dbo.Rezervare", "spectatorId", "dbo.Spectator", "id", cascadeDelete: true);
            AddForeignKey("dbo.Rezervare", "piesaId", "dbo.Piesa", "id", cascadeDelete: true);
            AddForeignKey("dbo.Rezervare", "locId", "dbo.Loc", "id", cascadeDelete: true);
        }
    }
}
