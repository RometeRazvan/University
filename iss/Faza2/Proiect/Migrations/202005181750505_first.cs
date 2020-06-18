namespace Faza2.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class first : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.Loc",
                c => new
                    {
                        id = c.Guid(nullable: false, identity: true),
                        pozitie = c.String(maxLength: 20),
                        pret = c.Int(nullable: false),
                        liber = c.Boolean(nullable: false),
                    })
                .PrimaryKey(t => t.id);
            
            CreateTable(
                "dbo.Manager",
                c => new
                    {
                        id = c.Guid(nullable: false, identity: true),
                        username = c.String(maxLength: 20),
                        password = c.String(maxLength: 20),
                        teatruId = c.Guid(nullable: false),
                    })
                .PrimaryKey(t => t.id)
                .ForeignKey("dbo.Teatru", t => t.teatruId, cascadeDelete: true)
                .Index(t => t.teatruId);
            
            CreateTable(
                "dbo.Teatru",
                c => new
                    {
                        id = c.Guid(nullable: false, identity: true),
                        nume = c.String(maxLength: 20),
                    })
                .PrimaryKey(t => t.id);
            
            CreateTable(
                "dbo.Piesa",
                c => new
                    {
                        id = c.Guid(nullable: false, identity: true),
                        teatruId = c.Guid(nullable: false),
                        nume = c.String(maxLength: 20),
                    })
                .PrimaryKey(t => t.id)
                .ForeignKey("dbo.Teatru", t => t.teatruId, cascadeDelete: true)
                .Index(t => t.teatruId);
            
            CreateTable(
                "dbo.Spectator",
                c => new
                    {
                        id = c.Guid(nullable: false, identity: true),
                        nume = c.String(maxLength: 20),
                        telefon = c.String(maxLength: 20),
                        email = c.String(maxLength: 30),
                    })
                .PrimaryKey(t => t.id);
            
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Piesa", "teatruId", "dbo.Teatru");
            DropForeignKey("dbo.Manager", "teatruId", "dbo.Teatru");
            DropIndex("dbo.Piesa", new[] { "teatruId" });
            DropIndex("dbo.Manager", new[] { "teatruId" });
            DropTable("dbo.Spectator");
            DropTable("dbo.Piesa");
            DropTable("dbo.Teatru");
            DropTable("dbo.Manager");
            DropTable("dbo.Loc");
        }
    }
}
