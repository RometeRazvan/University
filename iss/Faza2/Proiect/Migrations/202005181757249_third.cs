namespace Faza2.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class third : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.Rezervare",
                c => new
                    {
                        id = c.Guid(nullable: false, identity: true),
                        piesaId = c.Guid(nullable: false),
                        spectatorId = c.Guid(nullable: false),
                        locId = c.Guid(nullable: false),
                    })
                .PrimaryKey(t => t.id)
                .ForeignKey("dbo.Loc", t => t.locId, cascadeDelete: true)
                .ForeignKey("dbo.Piesa", t => t.piesaId, cascadeDelete: true)
                .ForeignKey("dbo.Spectator", t => t.spectatorId, cascadeDelete: true)
                .Index(t => t.piesaId)
                .Index(t => t.spectatorId)
                .Index(t => t.locId);
            
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Rezervare", "spectatorId", "dbo.Spectator");
            DropForeignKey("dbo.Rezervare", "piesaId", "dbo.Piesa");
            DropForeignKey("dbo.Rezervare", "locId", "dbo.Loc");
            DropIndex("dbo.Rezervare", new[] { "locId" });
            DropIndex("dbo.Rezervare", new[] { "spectatorId" });
            DropIndex("dbo.Rezervare", new[] { "piesaId" });
            DropTable("dbo.Rezervare");
        }
    }
}
