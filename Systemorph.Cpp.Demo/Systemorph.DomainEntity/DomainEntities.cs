using System;
using Systemorph.Domain;
using Systemorph.Layout;

namespace Systemorph.DomainEntity
{
    [CatalogMenu("Default Domain")]
    public class Contract : NamedEntity
    {
        public virtual DateTime InceptionDate { get; set; }
    }

    [CatalogMenu("Default Domain")]
    public class CashFlow : NamedEntity
    {
        public virtual Contract Contract { get; set; }
        public virtual LegalEntity LegalEntity { get; set; }
    }

    [CatalogMenu("Default Domain")]
    public class LegalEntity : Dimension
    {
    } 
}
