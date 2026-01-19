using System.Threading.Tasks;

namespace Almostengr.AlmostengrWebsite.Common.Common.Infrastructure.Interfaces;

public interface IAeJson
{
    Task<T> GetRequestAsync<T>(string url) where T : class;
}