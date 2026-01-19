using System.Threading.Tasks;

namespace Almostengr.AlmostengrWebsite.Common.GardeningData.DomainServices.Interfaces;

public interface IAddDataToFileService
{
    Task<int> ExecuteAsync();
}
